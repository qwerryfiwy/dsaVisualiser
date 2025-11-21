#include "dsa/stacks_queues.h"

void dsa_stack_next_greater(SimulationContext* ctx, int32_t* arr, int size, int32_t* output) {
    Stack* s = dsa_stack_create(ctx, size); // Stores INDICES
    dsa_log_info(ctx, "Next Greater Element");

    for (int i = 0; i < size; i++) {
        output[i] = -1; // Default
    }

    for (int i = 0; i < size; i++) {
        while (!dsa_stack_isempty(s) && arr[dsa_stack_peek(ctx, s)] < arr[i]) {
            int idx = dsa_stack_pop(ctx, s);
            output[idx] = arr[i];
            // Visual: Arrow from idx to i
            dsa_log_array(ctx, OP_ARR_WRITE, idx, i, arr[i]); 
        }
        dsa_stack_push(ctx, s, i);
    }
}
