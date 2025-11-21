#include "dsa/lists.h"

ListNode* dsa_dll_reverse(SimulationContext* ctx, ListNode* head) {
    ListNode *temp = NULL;
    ListNode *current = head;
    dsa_log_info(ctx, "Reversing DLL");

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Visualizing the swap of pointers
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)current, (uint64_t)current->next, 0);
        
        current = current->prev; // Move to next (which is now prev)
    }

    if (temp != NULL) head = temp->prev;
    dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)head, 0, 0);
    return head;
}
