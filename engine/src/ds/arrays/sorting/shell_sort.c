#include "dsa/arrays.h"

void dsa_sort_shell(SimulationContext* ctx, int32_t* arr, int size) {
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i += 1) {
            int temp = arr[i];
            int j;
            dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, temp);
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                dsa_log_array(ctx, OP_ARR_COMPARE, j-gap, -1, temp);
                arr[j] = arr[j - gap];
                dsa_log_array(ctx, OP_ARR_WRITE, j, -1, arr[j-gap]);
            }
            arr[j] = temp;
            dsa_log_array(ctx, OP_ARR_WRITE, j, -1, temp);
        }
    }
}
