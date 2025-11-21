#ifndef DSA_TREES_H
#define DSA_TREES_H
#include "core_types.h"
#include "logger.h"

typedef struct TreeNode {
    int32_t value;
    struct TreeNode *left, *right;
    int height;
} TreeNode;

TreeNode* dsa_bst_insert(SimulationContext* ctx, TreeNode* root, int32_t val);
TreeNode* dsa_bst_search(SimulationContext* ctx, TreeNode* root, int32_t val);
void dsa_tree_inorder(SimulationContext* ctx, TreeNode* root);
void dsa_tree_preorder(SimulationContext* ctx, TreeNode* root);
void dsa_tree_postorder(SimulationContext* ctx, TreeNode* root);
#endif
