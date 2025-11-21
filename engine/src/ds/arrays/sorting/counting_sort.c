#include "dsa/arrays.h"
#include <stdlib.h>

void dsa_sort_counting(SimulationContext* ctx, int32_t* arr, int size) {
    // Finding Max
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    
    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));

    dsa_log_info(ctx, "Building Count Array");
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, arr[i]); // Visualize scan
    }
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];
    
    dsa_log_info(ctx, "Building Output");
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
        dsa_log_array(ctx, OP_ARR_WRITE, i, -1, arr[i]);
    }
    free(count);
    free(output);
}
