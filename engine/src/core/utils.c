#include "include/dsa/utils.h"
#include <stdlib.h>
#include <time.h>

// Internal flag to ensure we don't re-seed multiple times unnecessarily
static bool _seeded = false;

void dsa_utils_seed_random(void) {
    if (!_seeded) {
        srand((unsigned int)time(NULL));
        _seeded = true;
    }
}

int dsa_utils_random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void dsa_utils_swap(int32_t* a, int32_t* b) {
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

// Fisher-Yates Shuffle Algorithm
void dsa_utils_shuffle(int32_t* arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = dsa_utils_random_int(0, i);
        dsa_utils_swap(&arr[i], &arr[j]);
    }
}

bool dsa_utils_is_sorted(int32_t* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
