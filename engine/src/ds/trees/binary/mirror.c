#include "dsa/trees.h"

void dsa_tree_mirror(SimulationContext* ctx, TreeNode* root) {
    if (root == NULL) return;
    
    dsa_tree_mirror(ctx, root->left);
    dsa_tree_mirror(ctx, root->right);

    // Swap pointers
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Visualize swap
    dsa_log_tree(ctx, OP_TREE_LINK_LEFT, (uint64_t)root, (int32_t)(uint64_t)root->left);
    dsa_log_tree(ctx, OP_TREE_LINK_RIGHT, (uint64_t)root, (int32_t)(uint64_t)root->right);
}
