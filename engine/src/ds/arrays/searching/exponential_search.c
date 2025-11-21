#include "dsa/arrays.h"
#include <math.h>

// Uses binary search internally
static int binary_search_range(SimulationContext* ctx, int32_t* arr, int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        dsa_log_array(ctx, OP_ARR_COMPARE, mid, -1, x);
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int dsa_exponential_search(SimulationContext* ctx, int32_t* arr, int size, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < size && arr[i] <= target) {
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, arr[i]);
        i = i * 2;
    }
    return binary_search_range(ctx, arr, i/2, fmin(i, size-1), target);
}
