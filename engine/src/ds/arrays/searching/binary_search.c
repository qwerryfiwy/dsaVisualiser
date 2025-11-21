#include "dsa/arrays.h"

int dsa_binary_search(SimulationContext* ctx, int32_t* arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, mid, -1, arr[mid]); // Highlight mid
        dsa_log_array(ctx, OP_ARR_COMPARE, mid, -1, target);

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
