#include "dsa/arrays.h"
#include <stdlib.h>

static void merge(SimulationContext* ctx, int32_t* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Temp arrays (For visual simplicity we just alloc/free)
    int32_t* L = (int32_t*)malloc(n1 * sizeof(int32_t));
    int32_t* R = (int32_t*)malloc(n2 * sizeof(int32_t));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        dsa_log_array(ctx, OP_ARR_COMPARE, l+i, m+1+j, 0); // Approximate visualization
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            dsa_log_array(ctx, OP_ARR_WRITE, k, -1, L[i]);
            i++;
        } else {
            arr[k] = R[j];
            dsa_log_array(ctx, OP_ARR_WRITE, k, -1, R[j]);
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        dsa_log_array(ctx, OP_ARR_WRITE, k, -1, L[i]);
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        dsa_log_array(ctx, OP_ARR_WRITE, k, -1, R[j]);
        j++; k++;
    }
    free(L); free(R);
}

void dsa_sort_merge(SimulationContext* ctx, int32_t* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        dsa_sort_merge(ctx, arr, l, m);
        dsa_sort_merge(ctx, arr, m + 1, r);
        merge(ctx, arr, l, m, r);
    }
}
