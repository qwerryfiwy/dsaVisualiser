#include "dsa/stacks_queues.h"
#include <stdlib.h>

Stack* dsa_stack_create(SimulationContext* ctx, int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int32_t*)calloc(capacity, sizeof(int32_t));
    s->top = -1;
    s->capacity = capacity;
    dsa_log_info(ctx, "Stack Created");
    return s;
}

void dsa_stack_push(SimulationContext* ctx, Stack* s, int32_t value) {
    if (s->top >= s->capacity - 1) {
        dsa_log_info(ctx, "Stack Overflow");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    // Visual: Highlight 'top' index moving up and writing value
    dsa_log_array(ctx, OP_ARR_WRITE, s->top, -1, value);
}

int32_t dsa_stack_pop(SimulationContext* ctx, Stack* s) {
    if (s->top < 0) {
        dsa_log_info(ctx, "Stack Underflow");
        return -1;
    }
    int32_t val = s->data[s->top];
    dsa_log_array(ctx, OP_ARR_HIGHLIGHT, s->top, -1, 0); // Highlight removal
    s->top--;
    return val;
}

int32_t dsa_stack_peek(SimulationContext* ctx, Stack* s) {
    if (s->top < 0) return -1;
    dsa_log_array(ctx, OP_ARR_HIGHLIGHT, s->top, -1, s->data[s->top]);
    return s->data[s->top];
}

bool dsa_stack_isempty(Stack* s) { return s->top == -1; }
