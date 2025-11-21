#include "dsa/arrays.h"
#include "dsa/logger.h"

static int partition(SimulationContext* ctx, int32_t* arr, int low, int high) {
    int pivot_value = arr[high];
    dsa_log_array(ctx, OP_ARR_HIGHLIGHT, high, -1, pivot_value);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        dsa_log_array(ctx, OP_ARR_COMPARE, j, high, 0);
        if (arr[j] < pivot_value) {
            i++;
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                dsa_log_array(ctx, OP_ARR_SWAP, i, j, 0);
            }
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    dsa_log_array(ctx, OP_ARR_SWAP, i + 1, high, 0);
    return (i + 1);
}

void dsa_sort_quick(SimulationContext* ctx, int32_t* arr, int low, int high) {
    if (low < high) {
        int pi = partition(ctx, arr, low, high);
        dsa_sort_quick(ctx, arr, low, pi - 1);
        dsa_sort_quick(ctx, arr, pi + 1, high);
    }
}
