#include "dsa/lists.h"

ListNode* dsa_sll_reverse(SimulationContext* ctx, ListNode* head) {
    dsa_log_info(ctx, "Reversing List");
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    while (current != NULL) {
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)current, 0, 0);
        
        next = current->next;  // Store next
        
        current->next = prev;  // Reverse link
        // Visual: Current -> Prev
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)current, (uint64_t)prev, 0);
        
        prev = current;        // Move pointers
        current = next;
    }
    head = prev;
    dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)head, 0, 0);
    return head;
}
