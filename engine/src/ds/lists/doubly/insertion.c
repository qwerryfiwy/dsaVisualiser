#include "dsa/lists.h"
#include <stdlib.h>

void dsa_dll_insert_head(SimulationContext* ctx, ListNode** head, int32_t value) {
    dsa_log_info(ctx, "DLL Insert Head");
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = (*head);
    new_node->prev = NULL;
    dsa_log_graph(ctx, OP_ALLOC, (uint64_t)new_node, 0, value);

    if ((*head) != NULL) {
        (*head)->prev = new_node;
        dsa_log_graph(ctx, OP_LIST_PREV, (uint64_t)(*head), (uint64_t)new_node, 0);
    }
    
    (*head) = new_node;
    dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)*head, 0, 0);
}

void dsa_dll_insert_tail(SimulationContext* ctx, ListNode** head, int32_t value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = NULL;
    dsa_log_graph(ctx, OP_ALLOC, (uint64_t)new_node, 0, value);

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    ListNode* last = *head;
    while (last->next != NULL) last = last->next;

    last->next = new_node;
    new_node->prev = last;
    dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)last, (uint64_t)new_node, 0);
    dsa_log_graph(ctx, OP_LIST_PREV, (uint64_t)new_node, (uint64_t)last, 0);
}
