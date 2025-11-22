#include "dsa/arrays.h"
#include <math.h>

int dsa_jump_search(SimulationContext* ctx, int32_t* arr, int size, int target) {
    int step = (int)sqrt((double)size);
    int prev = 0;
    
    dsa_log_info(ctx, "Starting Jump Search");
    while (arr[(step < size ? step : size) - 1] < target) {
        dsa_log_array(ctx, OP_ARR_COMPARE, (step < size ? step : size) - 1, -1, target);
        prev = step;
        step += (int)sqrt((double)size);
        if (prev >= size) return -1;
    }

    for (int i = prev; i < (step < size ? step : size); i++) {
        dsa_log_array(ctx, OP_ARR_COMPARE, i, -1, target);
        if (arr[i] == target) return i;
    }
    return -1;
}
