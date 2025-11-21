#ifndef DSA_UTILS_H
#define DSA_UTILS_H

#include <stdint.h>
#include <stdbool.h>

// --- RANDOMNESS ---
// Seed the random number generator (call once at start)
void dsa_utils_seed_random(void);

// Get a random integer between min and max (inclusive)
int dsa_utils_random_int(int min, int max);

// --- ARRAY HELPERS ---
// Standard Fisher-Yates shuffle
void dsa_utils_shuffle(int32_t* arr, int size);

// Check if array is sorted (ascending)
bool dsa_utils_is_sorted(int32_t* arr, int size);

// Basic pointer swap (does NOT log events, just moves memory)
void dsa_utils_swap(int32_t* a, int32_t* b);

#endif // DSA_UTILS_H
