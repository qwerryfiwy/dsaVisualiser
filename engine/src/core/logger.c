#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/dsa/logger.h"

#define INITIAL_CAPACITY 128

// --- INTERNAL HELPERS ---

static void ensure_capacity(SimulationContext* ctx) {
    if (ctx->count >= ctx->capacity) {
        size_t new_cap = ctx->capacity == 0 ? INITIAL_CAPACITY : ctx->capacity * 2;
        SimulationEvent* new_buffer = (SimulationEvent*)realloc(ctx->event_buffer, new_cap * sizeof(SimulationEvent));
        
        if (!new_buffer) {
            fprintf(stderr, "[DSA Engine] Critical: Failed to realloc event buffer.\n");
            exit(1); 
        }
        
        ctx->event_buffer = new_buffer;
        ctx->capacity = new_cap;
    }
}

static void push_event(SimulationContext* ctx, OpCode op, EventPayload payload) {
    ensure_capacity(ctx);
    
    SimulationEvent* event = &ctx->event_buffer[ctx->count];
    event->step_id = (uint32_t)ctx->count;
    event->op = op;
    event->data = payload;
    
    ctx->count++;
}

// --- CONTEXT MANAGEMENT ---

SimulationContext* dsa_context_create(void) {
    SimulationContext* ctx = (SimulationContext*)malloc(sizeof(SimulationContext));
    if (!ctx) return NULL;
    
    ctx->event_buffer = NULL;
    ctx->capacity = 0;
    ctx->count = 0;
    ctx->detailed_mode = 1; // Default to high detail
    
    ensure_capacity(ctx);
    return ctx;
}

void dsa_context_free(SimulationContext* ctx) {
    if (ctx) {
        if (ctx->event_buffer) free(ctx->event_buffer);
        free(ctx);
    }
}

SimulationEvent* dsa_context_get_events(SimulationContext* ctx) {
    return ctx->event_buffer;
}

size_t dsa_context_get_count(SimulationContext* ctx) {
    return ctx->count;
}

// --- TYPED LOGGERS ---

void dsa_log_array(SimulationContext* ctx, OpCode op, int32_t idx_a, int32_t idx_b, int32_t value) {
    EventPayload p;
    // Zero out memory to ensure clean unions
    memset(&p, 0, sizeof(EventPayload));
    
    p.array.idx_a = idx_a;
    p.array.idx_b = idx_b;
    p.array.value = value;
    push_event(ctx, op, p);
}

void dsa_log_graph(SimulationContext* ctx, OpCode op, uint64_t node_a, uint64_t node_b, int32_t weight) {
    EventPayload p;
    memset(&p, 0, sizeof(EventPayload));

    p.graph.node_a = node_a;
    p.graph.node_b = node_b;
    p.graph.weight = weight;
    p.graph.metadata = 0;
    push_event(ctx, op, p);
}

void dsa_log_tree(SimulationContext* ctx, OpCode op, uint64_t node_id, int32_t extra_data) {
    EventPayload p;
    memset(&p, 0, sizeof(EventPayload));

    p.graph.node_a = node_id;
    p.graph.node_b = 0;
    p.graph.weight = 0;
    p.graph.metadata = extra_data; // e.g., height or balance factor
    push_event(ctx, op, p);
}

void dsa_log_path(SimulationContext* ctx, OpCode op, uint64_t node_id, double distance, double heuristic) {
    EventPayload p;
    memset(&p, 0, sizeof(EventPayload));

    p.path.node_id = node_id;
    p.path.distance = distance;
    p.path.heuristic = heuristic;
    push_event(ctx, op, p);
}

void dsa_log_grid(SimulationContext* ctx, OpCode op, int32_t row, int32_t col, int32_t val, int32_t old_val) {
    EventPayload p;
    memset(&p, 0, sizeof(EventPayload));

    p.grid.row = row;
    p.grid.col = col;
    p.grid.value = val;
    p.grid.old_value = old_val;
    push_event(ctx, op, p);
}

void dsa_log_info(SimulationContext* ctx, const char* message) {
    EventPayload p;
    memset(&p, 0, sizeof(EventPayload));

    // Safe string copy with truncation
    strncpy(p.info.text, message, sizeof(p.info.text) - 1);
    p.info.text[sizeof(p.info.text) - 1] = '\0';
    push_event(ctx, OP_MESSAGE, p);
}
