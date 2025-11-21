#include "dsa/lists.h"
#include <stdlib.h>

void dsa_sll_delete_node(SimulationContext* ctx, ListNode** head, int32_t value) {
    dsa_log_info(ctx, "Deleting Node");
    if (*head == NULL) return;

    ListNode *temp = *head, *prev = NULL;

    // If head holds the key
    if (temp != NULL && temp->value == value) {
        dsa_log_graph(ctx, OP_ARR_COMPARE, (uint64_t)temp, 0, value);
        *head = temp->next;
        dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)*head, 0, 0);
        dsa_log_graph(ctx, OP_FREE, (uint64_t)temp, 0, 0);
        free(temp);
        return;
    }

    // Search for key
    while (temp != NULL && temp->value != value) {
        dsa_log_graph(ctx, OP_LIST_VISIT, (uint64_t)temp, 0, 0);
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Not found

    // Unlink
    prev->next = temp->next;
    dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)prev, (uint64_t)temp->next, 0);
    dsa_log_graph(ctx, OP_FREE, (uint64_t)temp, 0, 0);
    free(temp);
}
