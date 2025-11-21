#ifndef DSA_DP_STRINGS_H
#define DSA_DP_STRINGS_H
#include "core_types.h"
#include "logger.h"

// DP
int dsa_dp_fib(SimulationContext* ctx, int n);
int dsa_dp_knapsack(SimulationContext* ctx, int W, int wt[], int val[], int n);

// Strings
void dsa_str_kmp(SimulationContext* ctx, char* txt, char* pat);
bool dsa_str_is_palindrome(SimulationContext* ctx, char* s);
#endif
