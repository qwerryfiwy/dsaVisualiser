#include "dsa/lists.h"

ListNode* dsa_sll_rotate(SimulationContext* ctx, ListNode* head, int k) {
    if (!head) return NULL;
    
    dsa_log_info(ctx, "Rotating List");
    
    // 1. Find length and tail
    ListNode* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    
    k = k % len;
    if (k == 0) return head;

    // 2. Make it circular temporarily
    tail->next = head; 
    dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)tail, (uint64_t)head, 0); // Visual loop

    // 3. Find new tail (len - k - 1) steps
    ListNode* new_tail = head;
    for (int i = 0; i < len - k - 1; i++) {
        new_tail = new_tail->next;
    }
    
    ListNode* new_head = new_tail->next;
    
    // 4. Break the loop
    new_tail->next = NULL;
    dsa_log_graph(ctx, OP_LIST_NEXT, (uint64_t)new_tail, 0, 0); // Visual break
    dsa_log_graph(ctx, OP_LIST_HEAD_UPDATE, (uint64_t)new_head, 0, 0);

    return new_head;
}
