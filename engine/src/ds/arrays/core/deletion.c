#include "dsa/arrays.h"

void dsa_array_delete(SimulationContext* ctx, int32_t* arr, int* size, int index) {
    dsa_log_info(ctx, "Deleting value...");
    if (index < 0 || index >= *size) return;

    int deleted_val = arr[index];
    dsa_log_array(ctx, OP_ARR_HIGHLIGHT, index, -1, deleted_val);

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i+1];
        dsa_log_array(ctx, OP_ARR_WRITE, i, -1, arr[i]);
    }
    (*size)--;
}
