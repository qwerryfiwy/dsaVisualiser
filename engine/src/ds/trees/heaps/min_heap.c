#include "dsa/trees.h"

static void swap(int32_t* a, int32_t* b) { int32_t t = *a; *a = *b; *b = t; }

void dsa_min_heap_insert(SimulationContext* ctx, int32_t* heap, int* size, int value) {
    dsa_log_info(ctx, "Heap Insert");
    int i = *size;
    heap[i] = value;
    dsa_log_array(ctx, OP_ARR_WRITE, i, -1, value);
    (*size)++;

    // Sift Up
    while (i != 0 && heap[(i-1)/2] > heap[i]) {
        dsa_log_array(ctx, OP_ARR_COMPARE, (i-1)/2, i, 0);
        dsa_log_array(ctx, OP_HEAP_SIFT_UP, i, (i-1)/2, 0); // Visual Sift
        swap(&heap[i], &heap[(i-1)/2]);
        dsa_log_array(ctx, OP_ARR_SWAP, i, (i-1)/2, 0);
        i = (i-1)/2;
    }
}

void dsa_heapify(SimulationContext* ctx, int32_t* arr, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n) {
        dsa_log_array(ctx, OP_ARR_COMPARE, l, smallest, 0);
        if (arr[l] < arr[smallest]) smallest = l;
    }
    if (r < n) {
        dsa_log_array(ctx, OP_ARR_COMPARE, r, smallest, 0);
        if (arr[r] < arr[smallest]) smallest = r;
    }

    if (smallest != i) {
        dsa_log_array(ctx, OP_HEAP_SIFT_DOWN, i, smallest, 0);
        swap(&arr[i], &arr[smallest]);
        dsa_log_array(ctx, OP_ARR_SWAP, i, smallest, 0);
        dsa_heapify(ctx, arr, n, smallest);
    }
}
