#include "dsa/arrays.h"

void dsa_prob_kadane(SimulationContext* ctx, int32_t* arr, int size) {
    int max_so_far = arr[0];
    int curr_max = arr[0];

    dsa_log_info(ctx, "Starting Kadane's Algorithm");
    
    for (int i = 1; i < size; i++) {
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, arr[i]);
        
        // Logic: curr_max = max(arr[i], curr_max + arr[i])
        if (curr_max + arr[i] > arr[i]) {
            curr_max += arr[i];
        } else {
            curr_max = arr[i];
        }
        
        if (curr_max > max_so_far) {
            max_so_far = curr_max;
            dsa_log_info(ctx, "New Max Found");
        }
    }
}
