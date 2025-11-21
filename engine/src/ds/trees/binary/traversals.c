#include "dsa/trees.h"

void dsa_tree_inorder(SimulationContext* ctx, TreeNode* root) {
    if (root == NULL) return;
    dsa_tree_inorder(ctx, root->left);
    dsa_log_graph(ctx, OP_TREE_VISIT, (uint64_t)root, 0, 0);
    dsa_tree_inorder(ctx, root->right);
}

void dsa_tree_preorder(SimulationContext* ctx, TreeNode* root) {
    if (root == NULL) return;
    dsa_log_graph(ctx, OP_TREE_VISIT, (uint64_t)root, 0, 0);
    dsa_tree_preorder(ctx, root->left);
    dsa_tree_preorder(ctx, root->right);
}

void dsa_tree_postorder(SimulationContext* ctx, TreeNode* root) {
    if (root == NULL) return;
    dsa_tree_postorder(ctx, root->left);
    dsa_tree_postorder(ctx, root->right);
    dsa_log_graph(ctx, OP_TREE_VISIT, (uint64_t)root, 0, 0);
}

void dsa_tree_levelorder(SimulationContext* ctx, TreeNode* root) {
    dsa_log_info(ctx, "Level Order Traversal (Stub - Needs Queue)");
    if (root) dsa_log_graph(ctx, OP_TREE_VISIT, (uint64_t)root, 0, 0);
}
