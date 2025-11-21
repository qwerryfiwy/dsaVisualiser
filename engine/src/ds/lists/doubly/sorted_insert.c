#include "dsa/lists.h"
#include <stdlib.h>

void dsa_dll_sorted_insert(SimulationContext* ctx, ListNode** head, ListNode* new_node) {
    ListNode* current;

    if (*head == NULL) {
        *head = new_node;
        return;
    } 
    
    dsa_log_graph(ctx, OP_ARR_COMPARE, (uint64_t)(*head), (uint64_t)new_node, 0);
    
    if ((*head)->value >= new_node->value) {
        new_node->next = *head;
        new_node->next->prev = new_node;
        *head = new_node;
        dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)*head, 0, 0);
    } else {
        current = *head;
        while (current->next != NULL && current->next->value < new_node->value) {
            dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)current, 0, 0);
            current = current->next;
        }
        
        new_node->next = current->next;
        if (current->next != NULL) new_node->next->prev = new_node;
        
        current->next = new_node;
        new_node->prev = current;
        
        dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)current, (uint64_t)new_node, 0);
    }
}
