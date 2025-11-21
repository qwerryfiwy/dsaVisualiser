#include "dsa/arrays.h"
#include <stdlib.h>

// Returns new pointer (simulated)
void dsa_array_resize(SimulationContext* ctx, int32_t* arr, int old_size, int new_size) {
    dsa_log_info(ctx, "Resizing Array");
    dsa_log_array(ctx, OP_ALLOC, 0, 0, new_size); // Visual allocation
    
    for(int i=0; i<old_size && i<new_size; i++) {
        dsa_log_array(ctx, OP_ARR_COPY, i, i, arr[i]); // Visual copy
    }
}
