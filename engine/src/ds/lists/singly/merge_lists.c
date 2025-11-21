#include "dsa/lists.h"
#include <stdlib.h>

ListNode* dsa_sll_merge_sorted(SimulationContext* ctx, ListNode* l1, ListNode* l2) {
    dsa_log_info(ctx, "Merging Sorted Lists");
    
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode* head = NULL;
    
    // Visualize Comparison
    dsa_log_graph(ctx, OP_ARR_COMPARE, (uint64_t)l1, (uint64_t)l2, 0);
    
    if (l1->value <= l2->value) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)head, 0, 0);

    ListNode* curr = head;
    while (l1 && l2) {
        dsa_log_graph(ctx, OP_ARR_COMPARE, (uint64_t)l1, (uint64_t)l2, 0);
        if (l1->value <= l2->value) {
            curr->next = l1;
            dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)curr, (uint64_t)l1, 0);
            l1 = l1->next;
        } else {
            curr->next = l2;
            dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)curr, (uint64_t)l2, 0);
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if (l1) {
        curr->next = l1;
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)curr, (uint64_t)l1, 0);
    } else if (l2) {
        curr->next = l2;
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)curr, (uint64_t)l2, 0);
    }
    
    return head;
}
