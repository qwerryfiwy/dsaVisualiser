#include "dsa/lists.h"
#include <stdlib.h>

// Helper to get count
static int get_count(ListNode* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

ListNode* dsa_sll_intersection(SimulationContext* ctx, ListNode* headA, ListNode* headB) {
    int c1 = get_count(headA);
    int c2 = get_count(headB);
    int diff = abs(c1 - c2);

    dsa_log_info(ctx, "Finding Intersection (Diff Method)");

    ListNode* ptr1 = (c1 > c2) ? headA : headB;
    ListNode* ptr2 = (c1 > c2) ? headB : headA;

    // Move larger list pointer 'diff' steps
    for(int i=0; i<diff; i++) {
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)ptr1, 0, 0);
        ptr1 = ptr1->next;
    }

    while (ptr1 && ptr2) {
        dsa_log_graph(ctx, OP_ARR_COMPARE, (uint64_t)ptr1, (uint64_t)ptr2, 0);
        if (ptr1 == ptr2) {
            dsa_log_info(ctx, "Intersection Found");
            dsa_log_graph(ctx, OP_ARR_HIGHLIGHT, (uint64_t)ptr1, 0, ptr1->value);
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
