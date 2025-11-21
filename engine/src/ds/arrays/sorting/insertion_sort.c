#include "dsa/arrays.h"

void dsa_sort_insertion(SimulationContext* ctx, int32_t* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, key);

        while (j >= 0 && arr[j] > key) {
            dsa_log_array(ctx, OP_ARR_COMPARE, j, -1, key);
            arr[j + 1] = arr[j];
            dsa_log_array(ctx, OP_ARR_WRITE, j + 1, j, arr[j]); // Shift visualization
            j = j - 1;
        }
        arr[j + 1] = key;
        dsa_log_array(ctx, OP_ARR_WRITE, j + 1, -1, key);
    }
}
