#include "dsa/arrays.h"

void dsa_array_insert(SimulationContext* ctx, int32_t* arr, int* size, int capacity, int index, int value) {
    dsa_log_info(ctx, "Inserting value...");
    if (*size >= capacity) return;
    
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i-1];
        dsa_log_array(ctx, OP_ARR_WRITE, i, -1, arr[i]);
    }
    arr[index] = value;
    dsa_log_array(ctx, OP_ARR_WRITE, index, -1, value);
    (*size)++;
}
