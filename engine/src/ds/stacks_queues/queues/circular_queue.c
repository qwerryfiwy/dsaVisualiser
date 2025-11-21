#include "dsa/stacks_queues.h"

void dsa_cqueue_enqueue(SimulationContext* ctx, CircularQueue* q, int32_t value) {
    int next = (q->rear + 1) % q->capacity;
    if (next == q->front) {
        dsa_log_info(ctx, "Circular Queue Full");
        return;
    }
    q->data[q->rear] = value;
    dsa_log_array(ctx, OP_ARR_WRITE, q->rear, -1, value);
    q->rear = next;
}
