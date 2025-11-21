#include "dsa/arrays.h"

void dsa_prob_rainwater(SimulationContext* ctx, int32_t* height, int size) {
    int left = 0, right = size - 1;
    int left_max = 0, right_max = 0;
    int water = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= left_max) left_max = height[left];
            else {
                water += left_max - height[left];
                dsa_log_array(ctx, OP_ARR_HIGHLIGHT, left, -1, water); // Show trapped water
            }
            left++;
        } else {
            if (height[right] >= right_max) right_max = height[right];
            else {
                water += right_max - height[right];
                dsa_log_array(ctx, OP_ARR_HIGHLIGHT, right, -1, water);
            }
            right--;
        }
    }
}
