#include "dsa/arrays.h"

int dsa_linear_search(SimulationContext* ctx, int32_t* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        dsa_log_array(ctx, OP_ARR_COMPARE, i, -1, target);
        if (arr[i] == target) {
            dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, target);
            return i;
        }
    }
    return -1;
}
