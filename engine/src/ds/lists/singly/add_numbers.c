#include "dsa/lists.h"
#include <stdlib.h>

ListNode* dsa_sll_add_numbers(SimulationContext* ctx, ListNode* l1, ListNode* l2) {
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    ListNode* curr = dummy;
    int carry = 0;

    dsa_log_info(ctx, "Adding Numbers");

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->value;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->value;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        int digit = sum % 10;
        
        ListNode* new_node = dsa_sll_create_node(ctx, digit);
        curr->next = new_node;
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)curr, (uint64_t)new_node, 0);
        curr = curr->next;
    }
    
    return dummy->next;
}
