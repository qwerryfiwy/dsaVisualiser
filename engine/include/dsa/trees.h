#ifndef DSA_TREES_H
#define DSA_TREES_H

#include "core_types.h"
#include "logger.h"
#include <stdbool.h>

// --- BINARY TREE NODE ---
typedef struct TreeNode {
    int32_t value;
    struct TreeNode *left;
    struct TreeNode *right;
    int height; // For AVL
} TreeNode;

// --- BINARY TREE OPS ---
TreeNode* dsa_tree_create_node(SimulationContext* ctx, int32_t value);
void dsa_tree_inorder(SimulationContext* ctx, TreeNode* root);
void dsa_tree_preorder(SimulationContext* ctx, TreeNode* root);
void dsa_tree_postorder(SimulationContext* ctx, TreeNode* root);
void dsa_tree_levelorder(SimulationContext* ctx, TreeNode* root);
int dsa_tree_height(SimulationContext* ctx, TreeNode* root);
int dsa_tree_diameter(SimulationContext* ctx, TreeNode* root);
TreeNode* dsa_tree_lca(SimulationContext* ctx, TreeNode* root, int n1, int n2);
void dsa_tree_mirror(SimulationContext* ctx, TreeNode* root);
void dsa_tree_left_view(SimulationContext* ctx, TreeNode* root);

// --- BST OPS ---
TreeNode* dsa_bst_insert(SimulationContext* ctx, TreeNode* root, int32_t value);
TreeNode* dsa_bst_delete(SimulationContext* ctx, TreeNode* root, int32_t value);
TreeNode* dsa_bst_search(SimulationContext* ctx, TreeNode* root, int32_t value);
bool dsa_bst_validate(SimulationContext* ctx, TreeNode* root);
TreeNode* dsa_bst_kth_smallest(SimulationContext* ctx, TreeNode* root, int k);

// --- AVL OPS ---
TreeNode* dsa_avl_insert(SimulationContext* ctx, TreeNode* root, int32_t value);
TreeNode* dsa_avl_delete(SimulationContext* ctx, TreeNode* root, int32_t value);

// --- HEAP OPS ---
void dsa_min_heap_insert(SimulationContext* ctx, int32_t* heap, int* size, int value);
int32_t dsa_min_heap_extract(SimulationContext* ctx, int32_t* heap, int* size);
void dsa_heapify(SimulationContext* ctx, int32_t* arr, int n, int i);
void dsa_heap_sort_step(SimulationContext* ctx, int32_t* arr, int n);

#endif // DSA_TREES_H
