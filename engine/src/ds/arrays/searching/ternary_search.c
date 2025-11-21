#include "dsa/arrays.h"

int dsa_ternary_search(SimulationContext* ctx, int32_t* arr, int l, int r, int target) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        dsa_log_array(ctx, OP_ARR_COMPARE, mid1, -1, target);
        if (arr[mid1] == target) return mid1;
        
        dsa_log_array(ctx, OP_ARR_COMPARE, mid2, -1, target);
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) return dsa_ternary_search(ctx, arr, l, mid1 - 1, target);
        if (target > arr[mid2]) return dsa_ternary_search(ctx, arr, mid2 + 1, r, target);
        
        return dsa_ternary_search(ctx, arr, mid1 + 1, mid2 - 1, target);
    }
    return -1;
}
