#include "dsa/arrays.h"

static void heapify(SimulationContext* ctx, int32_t* arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n) {
        dsa_log_array(ctx, OP_ARR_COMPARE, left, largest, 0);
        if (arr[left] > arr[largest]) largest = left;
    }
    if (right < n) {
        dsa_log_array(ctx, OP_ARR_COMPARE, right, largest, 0);
        if (arr[right] > arr[largest]) largest = right;
    }
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        dsa_log_array(ctx, OP_ARR_SWAP, i, largest, 0);
        heapify(ctx, arr, n, largest);
    }
}

void dsa_sort_heap(SimulationContext* ctx, int32_t* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(ctx, arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        dsa_log_array(ctx, OP_ARR_SWAP, 0, i, 0);
        heapify(ctx, arr, i, 0);
    }
}
