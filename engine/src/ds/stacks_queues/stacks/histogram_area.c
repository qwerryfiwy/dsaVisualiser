#include "dsa/stacks_queues.h"

int dsa_stack_histogram_area(SimulationContext* ctx, int32_t* heights, int size) {
    Stack* s = dsa_stack_create(ctx, size); // Stores indices
    int max_area = 0;
    int i = 0;
    
    dsa_log_info(ctx, "Largest Histogram Area");

    while (i < size) {
        if (dsa_stack_isempty(s) || heights[dsa_stack_peek(ctx, s)] <= heights[i]) {
            dsa_stack_push(ctx, s, i++);
        } else {
            int tp = dsa_stack_pop(ctx, s);
            int width = dsa_stack_isempty(s) ? i : i - dsa_stack_peek(ctx, s) - 1;
            int area = heights[tp] * width;
            dsa_log_array(ctx, OP_ARR_HIGHLIGHT, tp, i, area); // Show calculated area
            
            if (area > max_area) max_area = area;
        }
    }
    // Clear remaining
    while (!dsa_stack_isempty(s)) {
        int tp = dsa_stack_pop(ctx, s);
        int width = dsa_stack_isempty(s) ? i : i - dsa_stack_peek(ctx, s) - 1;
        int area = heights[tp] * width;
        if (area > max_area) max_area = area;
    }
    return max_area;
}
