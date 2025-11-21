#include "dsa/stacks_queues.h"
#include <stdlib.h>

Queue* dsa_queue_create(SimulationContext* ctx, int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int32_t*)calloc(capacity, sizeof(int32_t));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    q->size = 0;
    dsa_log_info(ctx, "Queue Created");
    return q;
}

void dsa_queue_enqueue(SimulationContext* ctx, Queue* q, int32_t value) {
    if (q->size == q->capacity) return;
    q->data[q->rear] = value;
    dsa_log_array(ctx, OP_ARR_WRITE, q->rear, -1, value);
    q->rear = (q->rear + 1) % q->capacity; // Treat as simple buffer for visual
    q->size++;
}

int32_t dsa_queue_dequeue(SimulationContext* ctx, Queue* q) {
    if (q->size == 0) return -1;
    int32_t val = q->data[q->front];
    dsa_log_array(ctx, OP_ARR_HIGHLIGHT, q->front, -1, 0); // Highlight removal
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}
