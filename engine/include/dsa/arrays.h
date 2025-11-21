#ifndef DSA_ARRAYS_H
#define DSA_ARRAYS_H

#include "core_types.h"
#include "logger.h"
#include <stdbool.h>
#include <string.h>

// --- CORE OPERATIONS ---
void dsa_array_insert(SimulationContext* ctx, int32_t* arr, int* size, int capacity, int index, int value);
void dsa_array_delete(SimulationContext* ctx, int32_t* arr, int* size, int index);
void dsa_array_reverse(SimulationContext* ctx, int32_t* arr, int size);
void dsa_array_rotate(SimulationContext* ctx, int32_t* arr, int size, int k);

// --- SEARCHING ---
int dsa_linear_search(SimulationContext* ctx, int32_t* arr, int size, int target);
int dsa_binary_search(SimulationContext* ctx, int32_t* arr, int size, int target);
int dsa_jump_search(SimulationContext* ctx, int32_t* arr, int size, int target);
int dsa_interpolation_search(SimulationContext* ctx, int32_t* arr, int size, int target);
int dsa_exponential_search(SimulationContext* ctx, int32_t* arr, int size, int target);

// --- SORTING ---
void dsa_sort_bubble(SimulationContext* ctx, int32_t* arr, int size);
void dsa_sort_selection(SimulationContext* ctx, int32_t* arr, int size);
void dsa_sort_insertion(SimulationContext* ctx, int32_t* arr, int size);
void dsa_sort_merge(SimulationContext* ctx, int32_t* arr, int left, int right);
void dsa_sort_quick(SimulationContext* ctx, int32_t* arr, int low, int high);
void dsa_sort_heap(SimulationContext* ctx, int32_t* arr, int size);
void dsa_sort_shell(SimulationContext* ctx, int32_t* arr, int size);
void dsa_sort_counting(SimulationContext* ctx, int32_t* arr, int size);

// --- PROBLEMS ---
void dsa_prob_two_sum(SimulationContext* ctx, int32_t* arr, int size, int target);
void dsa_prob_kadane(SimulationContext* ctx, int32_t* arr, int size);
void dsa_prob_rainwater(SimulationContext* ctx, int32_t* height, int size);
void dsa_prob_dutch_flag(SimulationContext* ctx, int32_t* arr, int size);
void dsa_prob_stock_buy_sell(SimulationContext* ctx, int32_t* prices, int size);

#endif // DSA_ARRAYS_H
