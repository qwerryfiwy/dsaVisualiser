#include "dsa/lists.h"

ListNode* dsa_sll_nth_from_end(SimulationContext* ctx, ListNode* head, int n) {
    ListNode *main_ptr = head;
    ListNode *ref_ptr = head;

    dsa_log_info(ctx, "Finding Nth Node From End");

    int count = 0;
    while (count < n) {
        if (ref_ptr == NULL) return NULL;
        ref_ptr = ref_ptr->next;
        count++;
    }

    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)main_ptr, 0, 0); // Move sliding window
    }
    
    dsa_log_graph(ctx, OP_ARR_HIGHLIGHT, (uint64_t)main_ptr, 0, main_ptr->value);
    return main_ptr;
}
