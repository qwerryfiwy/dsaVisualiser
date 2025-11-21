#include "dsa/lists.h"
#include <stdlib.h>

void dsa_cll_insert(SimulationContext* ctx, ListNode** head, int32_t value) {
    ListNode* ptr1 = (ListNode*)malloc(sizeof(ListNode));
    ptr1->value = value;
    ptr1->next = ptr1; // Self loop initially
    dsa_log_graph(ctx, OP_ALLOC, (uint64_t)ptr1, 0, value);

    if (*head == NULL) {
        *head = ptr1;
        dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)*head, 0, 0);
    } else {
        ListNode *temp = *head;
        while (temp->next != *head) temp = temp->next;
        
        temp->next = ptr1;
        ptr1->next = *head;
        
        // Visualize circular link
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)temp, (uint64_t)ptr1, 0);
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)ptr1, (uint64_t)*head, 0);
    }
}
