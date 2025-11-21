#include "dsa/lists.h"

ListNode* dsa_sll_middle(SimulationContext* ctx, ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)slow, 0, 0);
    }
    dsa_log_graph(ctx, OP_ARR_HIGHLIGHT, (uint64_t)slow, 0, slow->value);
    return slow;
}
