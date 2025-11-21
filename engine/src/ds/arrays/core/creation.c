#include "dsa/arrays.h"
#include <stdlib.h>

void dsa_array_create(SimulationContext* ctx, int32_t* out_arr, int size) {
    dsa_log_info(ctx, "Creating Array");
    for(int i=0; i<size; i++) {
        out_arr[i] = 0; // Default init
        dsa_log_array(ctx, OP_ARR_WRITE, i, -1, 0);
    }
}
