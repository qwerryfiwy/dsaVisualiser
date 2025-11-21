#include "dsa/arrays.h"

void dsa_prob_stock_buy_sell(SimulationContext* ctx, int32_t* prices, int size) {
    int min_price = 2147483647; // INT_MAX
    int max_profit = 0;
    
    for (int i = 0; i < size; i++) {
        dsa_log_array(ctx, OP_ARR_HIGHLIGHT, i, -1, prices[i]);
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
            dsa_log_info(ctx, "New Max Profit");
        }
    }
}
