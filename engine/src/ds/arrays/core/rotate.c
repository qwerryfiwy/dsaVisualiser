#include "dsa/arrays.h"

// Helper for reversal algo
static void reverse_range(SimulationContext* ctx, int32_t* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        dsa_log_array(ctx, OP_ARR_SWAP, start, end, 0);
        start++;
        end--;
    }
}

void dsa_array_rotate(SimulationContext* ctx, int32_t* arr, int size, int k) {
    k = k % size;
    dsa_log_info(ctx, "Rotating Array");
    // Standard Reversal Algorithm: Reverse all, reverse first k, reverse rest
    reverse_range(ctx, arr, 0, size - 1);
    reverse_range(ctx, arr, 0, k - 1);
    reverse_range(ctx, arr, k, size - 1);
}
