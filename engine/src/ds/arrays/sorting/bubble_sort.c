#include "dsa/arrays.h"
#include "dsa/logger.h"

void dsa_sort_bubble(SimulationContext* ctx, int32_t* arr, int size) {
    dsa_log_info(ctx, "Starting Bubble Sort");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            dsa_log_array(ctx, OP_ARR_COMPARE, j, j + 1, 0);
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                dsa_log_array(ctx, OP_ARR_SWAP, j, j + 1, 0);
            }
        }
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, size - i - 1, -1, 0); 
    }
    dsa_log_info(ctx, "Bubble Sort Complete");
}
