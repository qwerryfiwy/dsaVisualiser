#include "dsa/arrays.h"

void dsa_prob_prefix_sum(SimulationContext* ctx, int32_t* arr, int size, int32_t* output) {
    output[0] = arr[0];
    dsa_log_array(ctx, OP_ARR_WRITE, 0, -1, output[0]);
    
    for(int i=1; i<size; i++) {
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, i-1, 0);
        output[i] = output[i-1] + arr[i];
        dsa_log_array(ctx, OP_ARR_WRITE, i, -1, output[i]);
    }
}
