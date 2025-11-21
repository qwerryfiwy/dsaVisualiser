#include "dsa/arrays.h"

int dsa_interpolation_search(SimulationContext* ctx, int32_t* arr, int size, int target) {
    int lo = 0, hi = size - 1;
    while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == target) return lo;
            return -1;
        }
        // Probing position formula
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (target - arr[lo]));
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, pos, -1, 0);
        
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) lo = pos + 1;
        else hi = pos - 1;
    }
    return -1;
}
