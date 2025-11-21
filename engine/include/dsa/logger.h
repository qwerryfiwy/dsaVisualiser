#ifndef DSA_LOGGER_H
#define DSA_LOGGER_H

#include "core_types.h"

// --- CONTEXT MANAGEMENT ---

// Initializes a new recording session with an empty event buffer.
SimulationContext* dsa_context_create(void);

// Frees the context and the underlying event buffer.
void dsa_context_free(SimulationContext* ctx);

// Returns a pointer to the raw array of events (for testing/debugging).
SimulationEvent* dsa_context_get_events(SimulationContext* ctx);

// Returns the number of recorded events.
size_t dsa_context_get_count(SimulationContext* ctx);


// --- LOGGING FUNCTIONS (Type-Safe Wrappers) ---

// Log a generic Array operation (Swap, Compare, Write, Highlight)
void dsa_log_array(SimulationContext* ctx, OpCode op, int32_t idx_a, int32_t idx_b, int32_t value);

// Log a Linked List / Graph / Tree node operation
void dsa_log_graph(SimulationContext* ctx, OpCode op, uint64_t node_a, uint64_t node_b, int32_t weight);

// Log a specific Tree rotation or generic tree link
void dsa_log_tree(SimulationContext* ctx, OpCode op, uint64_t node_id, int32_t extra_data);

// Log a Pathfinding step (Dijkstra/A*)
void dsa_log_path(SimulationContext* ctx, OpCode op, uint64_t node_id, double distance, double heuristic);

// Log a Grid/Matrix operation (DP, Backtracking)
void dsa_log_grid(SimulationContext* ctx, OpCode op, int32_t row, int32_t col, int32_t val, int32_t old_val);

// Log a simple text message
void dsa_log_info(SimulationContext* ctx, const char* message);

#endif // DSA_LOGGER_H