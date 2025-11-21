#include "dsa/stacks_queues.h"

void dsa_queue_sliding_window_max(SimulationContext* ctx, int32_t* arr, int size, int k) {
    // Ideally uses Deque, here we visualize the concept
    dsa_log_info(ctx, "Sliding Window Maximum");
    for (int i = 0; i <= size - k; i++) {
        int max_val = arr[i];
        for (int j = 1; j < k; j++) {
            if (arr[i+j] > max_val) max_val = arr[i+j];
        }
        // Highlight window
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, i+k-1, max_val);
    }
}
