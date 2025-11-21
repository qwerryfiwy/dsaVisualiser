#ifndef DSA_LISTS_H
#define DSA_LISTS_H

#include "core_types.h"
#include "logger.h"
#include <stdbool.h>

// Generic Node structure
typedef struct ListNode {
    int32_t value;
    struct ListNode* next;
    struct ListNode* prev; // For Doubly Linked List
} ListNode;

// --- SINGLY LINKED LIST ---
ListNode* dsa_sll_create_node(SimulationContext* ctx, int32_t value);
void dsa_sll_insert_head(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_sll_insert_tail(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_sll_delete_node(SimulationContext* ctx, ListNode** head, int32_t value);
ListNode* dsa_sll_search(SimulationContext* ctx, ListNode* head, int32_t value);
ListNode* dsa_sll_reverse(SimulationContext* ctx, ListNode* head);
bool dsa_sll_has_cycle(SimulationContext* ctx, ListNode* head);
ListNode* dsa_sll_middle(SimulationContext* ctx, ListNode* head);
bool dsa_sll_is_palindrome(SimulationContext* ctx, ListNode* head);

// --- DOUBLY LINKED LIST ---
void dsa_dll_insert_head(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_dll_insert_tail(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_dll_delete(SimulationContext* ctx, ListNode** head, int32_t value);
ListNode* dsa_dll_reverse(SimulationContext* ctx, ListNode* head);

// --- CIRCULAR LINKED LIST ---
void dsa_cll_insert(SimulationContext* ctx, ListNode** head, int32_t value);
void dsa_cll_delete(SimulationContext* ctx, ListNode** head, int32_t key);

#endif // DSA_LISTS_H
