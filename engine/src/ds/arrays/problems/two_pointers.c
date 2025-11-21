#include "dsa/arrays.h"

void dsa_prob_two_sum(SimulationContext* ctx, int32_t* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        dsa_log_array(ctx, OP_ARR_COMPARE, left, right, sum);
        
        if (sum == target) {
            dsa_log_info(ctx, "Target Found!");
            dsa_log_array(ctx, OP_ARR_HIGHLIGHT, left, right, sum);
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    dsa_log_info(ctx, "Target Not Found");
}
