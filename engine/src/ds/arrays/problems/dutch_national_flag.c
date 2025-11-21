#include "dsa/arrays.h"

void dsa_prob_dutch_flag(SimulationContext* ctx, int32_t* arr, int size) {
    int low = 0, mid = 0, high = size - 1;
    
    while (mid <= high) {
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, mid, -1, arr[mid]);
        switch(arr[mid]) {
            case 0:
                if (mid != low) dsa_log_array(ctx, OP_ARR_SWAP, low, mid, 0);
                { int t = arr[low]; arr[low] = arr[mid]; arr[mid] = t; }
                low++; mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                if (mid != high) dsa_log_array(ctx, OP_ARR_SWAP, mid, high, 0);
                { int t = arr[mid]; arr[mid] = arr[high]; arr[high] = t; }
                high--;
                break;
        }
    }
}
