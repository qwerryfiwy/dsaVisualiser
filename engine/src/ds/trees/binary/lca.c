#include "dsa/trees.h"

TreeNode* dsa_tree_lca(SimulationContext* ctx, TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;
    dsa_log_graph(ctx, OP_TREE_VISIT, (uint64_t)root, 0, 0);

    if (root->value == n1 || root->value == n2) {
        dsa_log_info(ctx, "Found Target Node");
        return root;
    }

    TreeNode* left_lca = dsa_tree_lca(ctx, root->left, n1, n2);
    TreeNode* right_lca = dsa_tree_lca(ctx, root->right, n1, n2);

    if (left_lca && right_lca) {
        dsa_log_info(ctx, "Found LCA");
        dsa_log_graph(ctx, OP_ARR_HIGHLIGHT, (uint64_t)root, 0, root->value);
        return root;
    }
    return (left_lca != NULL) ? left_lca : right_lca;
}
