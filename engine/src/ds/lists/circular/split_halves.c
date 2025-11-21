#include "dsa/lists.h"

void dsa_cll_split(SimulationContext* ctx, ListNode* head, ListNode** head1_ref, ListNode** head2_ref) {
    ListNode *slow = head;
    ListNode *fast = head;

    if (head == NULL) return;

    dsa_log_info(ctx, "Splitting Circular List");

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)slow, 0, 0);
    }

    if (fast->next->next == head) fast = fast->next;

    *head1_ref = head;
    if (head->next != head) *head2_ref = slow->next;

    fast->next = slow->next; // Make second half circular
    dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)fast, (uint64_t)slow->next, 0);

    slow->next = head;       // Make first half circular
    dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)slow, (uint64_t)head, 0);
}
