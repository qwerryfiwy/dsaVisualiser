#ifndef DSA_STACKS_QUEUES_H
#define DSA_STACKS_QUEUES_H

#include "core_types.h"
#include "logger.h"
#include <stdbool.h>

// --- STACK DEFINITION ---
typedef struct {
    int32_t* data;
    int top;
    int capacity;
} Stack;

// Core Operations
Stack* dsa_stack_create(SimulationContext* ctx, int capacity);
void dsa_stack_push(SimulationContext* ctx, Stack* s, int32_t value);
int32_t dsa_stack_pop(SimulationContext* ctx, Stack* s);
int32_t dsa_stack_peek(SimulationContext* ctx, Stack* s);
bool dsa_stack_isempty(Stack* s);

// Algorithms
void dsa_stack_infix_to_postfix(SimulationContext* ctx, char* infix, char* postfix);
int dsa_stack_eval_postfix(SimulationContext* ctx, char* postfix);
bool dsa_stack_balanced_parens(SimulationContext* ctx, char* expr);
void dsa_stack_next_greater(SimulationContext* ctx, int32_t* arr, int size, int32_t* output);
void dsa_stack_stock_span(SimulationContext* ctx, int32_t* prices, int size, int32_t* spans);
int dsa_stack_histogram_area(SimulationContext* ctx, int32_t* heights, int size);
// Min Stack (Logically handled via separate struct usually, implementing functional wrapper here)
void dsa_min_stack_demo(SimulationContext* ctx, int32_t* ops, int size);

// --- QUEUE DEFINITION ---
typedef struct {
    int32_t* data;
    int front, rear, size, capacity;
} Queue;

// Core Operations
Queue* dsa_queue_create(SimulationContext* ctx, int capacity);
void dsa_queue_enqueue(SimulationContext* ctx, Queue* q, int32_t value);
int32_t dsa_queue_dequeue(SimulationContext* ctx, Queue* q);
int32_t dsa_queue_peek(SimulationContext* ctx, Queue* q);

// Circular Queue
typedef struct {
    int32_t* data;
    int front, rear, capacity;
} CircularQueue;
void dsa_cqueue_enqueue(SimulationContext* ctx, CircularQueue* q, int32_t value);
int32_t dsa_cqueue_dequeue(SimulationContext* ctx, CircularQueue* q);

// Deque
typedef struct {
    int32_t* data;
    int front, rear, size, capacity;
} Deque;
void dsa_deque_push_front(SimulationContext* ctx, Deque* dq, int32_t val);
void dsa_deque_push_rear(SimulationContext* ctx, Deque* dq, int32_t val);
int32_t dsa_deque_pop_front(SimulationContext* ctx, Deque* dq);
int32_t dsa_deque_pop_rear(SimulationContext* ctx, Deque* dq);

// Algorithms
void dsa_queue_sliding_window_max(SimulationContext* ctx, int32_t* arr, int size, int k);
int dsa_queue_rotten_oranges(SimulationContext* ctx, int32_t* grid, int rows, int cols);

#endif // DSA_STACKS_QUEUES_H
