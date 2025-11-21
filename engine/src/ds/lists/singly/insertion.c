#include "dsa/lists.h"
#include <stdlib.h>

ListNode* dsa_sll_create_node(SimulationContext* ctx, int32_t value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = NULL;
    
    // Log allocation event (visualize generic new node)
    dsa_log_graph(ctx, OP_ALLOC, (uint64_t)new_node, 0, value);
    return new_node;
}

void dsa_sll_insert_head(SimulationContext* ctx, ListNode** head, int32_t value) {
    dsa_log_info(ctx, "Inserting at Head");
    ListNode* new_node = dsa_sll_create_node(ctx, value);
    
    if (*head != NULL) {
        new_node->next = *head;
        // Visualize link: New -> OldHead
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)new_node, (uint64_t)*head, 0);
    }
    *head = new_node;
    dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)*head, 0, 0);
}

void dsa_sll_insert_tail(SimulationContext* ctx, ListNode** head, int32_t value) {
    dsa_log_info(ctx, "Inserting at Tail");
    ListNode* new_node = dsa_sll_create_node(ctx, value);
    
    if (*head == NULL) {
        *head = new_node;
        dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)*head, 0, 0);
        return;
    }
    
    ListNode* temp = *head;
    while (temp->next != NULL) {
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)temp, 0, 0);
        temp = temp->next;
    }
    
    temp->next = new_node;
    // Visualize link: Last -> New
    dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)temp, (uint64_t)new_node, 0);
}
