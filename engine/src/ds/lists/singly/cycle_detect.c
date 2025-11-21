#include "dsa/lists.h"

bool dsa_sll_has_cycle(SimulationContext* ctx, ListNode* head) {
    ListNode *slow = head, *fast = head;
    dsa_log_info(ctx, "Checking for Cycle (Floyd's)");

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)slow, 0, 1); // 1=Slow color
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)fast, 0, 2); // 2=Fast color

        if (slow == fast) {
            dsa_log_info(ctx, "Cycle Detected!");
            return true;
        }
    }
    return false;
}
