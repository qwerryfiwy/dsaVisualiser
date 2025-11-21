#include "dsa/arrays.h"

void dsa_array_reverse(SimulationContext* ctx, int32_t* arr, int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        dsa_log_array(ctx, OP_ARR_COMPARE, left, right, 0);
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        dsa_log_array(ctx, OP_ARR_SWAP, left, right, 0);
        left++;
        right--;
    }
}
