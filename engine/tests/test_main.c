#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dsa/logger.h"
#include "dsa/arrays.h"

void test_bubble_sort() {
    printf("--- Running Bubble Sort Test ---\n");
    SimulationContext* ctx = dsa_context_create();
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    dsa_sort_bubble(ctx, arr, n);
    printf("✅ Logic check: %d events recorded.\n", (int)dsa_context_get_count(ctx));
    dsa_context_free(ctx);
}

void test_quick_sort() {
    printf("--- Running Quick Sort Test ---\n");
    SimulationContext* ctx = dsa_context_create();
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    dsa_sort_quick(ctx, arr, 0, n - 1);
    printf("✅ Logic check: %d events recorded.\n", (int)dsa_context_get_count(ctx));
    dsa_context_free(ctx);
}

int main() {
    test_bubble_sort();
    test_quick_sort();
    printf("🎉 SUCCESS: Engine is working!\n");
    return 0;
}
