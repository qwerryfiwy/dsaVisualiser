#include "dsa/arrays.h"

void dsa_prob_sliding_window_max_sum(SimulationContext* ctx, int32_t* arr, int size, int k) {
    if (size < k) return;
    int max_sum = 0;
    for(int i=0; i<k; i++) max_sum += arr[i];
    
    int window_sum = max_sum;
    dsa_log_info(ctx, "Initial Window");
    
    for(int i=k; i<size; i++) {
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, i-k, 0);
        window_sum += arr[i] - arr[i-k];
        if(window_sum > max_sum) max_sum = window_sum;
    }
}
