#include "dsa/arrays.h"

void dsa_sort_selection(SimulationContext* ctx, int32_t* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        int min_idx = i;
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, 0); // Current position
        
        for (int j = i+1; j < size; j++) {
            dsa_log_array(ctx, OP_ARR_COMPARE, j, min_idx, 0);
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                dsa_log_array(ctx, OP_ARR_HIGHLIGHT, min_idx, -1, 0); // New min found
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            dsa_log_array(ctx, OP_ARR_SWAP, i, min_idx, 0);
        }
    }
}
