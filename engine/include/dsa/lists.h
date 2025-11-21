#ifndef DSA_LISTS_H
#define DSA_LISTS_H

#include "core_types.h"
#include "logger.h"
#include <stdbool.h>

typedef struct ListNode {
    int32_t value;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

// --- SINGLY ---
ListNode* dsa_sll_create_node(SimulationContext* ctx, int32_t value);
void dsa_sll_insert_head(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_sll_insert_tail(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_sll_delete_node(SimulationContext* ctx, ListNode** head, int32_t value);
ListNode* dsa_sll_reverse(SimulationContext* ctx, ListNode* head);
bool dsa_sll_has_cycle(SimulationContext* ctx, ListNode* head);
ListNode* dsa_sll_middle(SimulationContext* ctx, ListNode* head);
bool dsa_sll_is_palindrome(SimulationContext* ctx, ListNode* head);

// Advanced Singly
ListNode* dsa_sll_merge_sorted(SimulationContext* ctx, ListNode* l1, ListNode* l2);
ListNode* dsa_sll_intersection(SimulationContext* ctx, ListNode* headA, ListNode* headB);
ListNode* dsa_sll_rotate(SimulationContext* ctx, ListNode* head, int k);
ListNode* dsa_sll_nth_from_end(SimulationContext* ctx, ListNode* head, int n);
ListNode* dsa_sll_add_numbers(SimulationContext* ctx, ListNode* l1, ListNode* l2);

// --- DOUBLY ---
void dsa_dll_insert_head(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_dll_insert_tail(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_dll_delete(SimulationContext* ctx, ListNode** head, int32_t value);
ListNode* dsa_dll_reverse(SimulationContext* ctx, ListNode* head);
void dsa_dll_sorted_insert(SimulationContext* ctx, ListNode** head, ListNode* new_node);

// --- CIRCULAR ---
void dsa_cll_insert(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_cll_split(SimulationContext* ctx, ListNode* head, ListNode** head1_ref, ListNode** head2_ref);

#endif // DSA_LISTS_H
