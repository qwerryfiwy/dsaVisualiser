#include "dsa/arrays.h"

void dsa_array_set(SimulationContext* ctx, int32_t* arr, int index, int value) {
    dsa_log_array(ctx, OP_ARR_WRITE, index, -1, value);
    arr[index] = value;
}

int32_t dsa_array_get(SimulationContext* ctx, int32_t* arr, int index) {
    dsa_log_array(ctx, OP_ARR_HIGHLIGHT, index, -1, arr[index]);
    return arr[index];
}
