#include "dsa/trees.h"
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int dsa_tree_height(SimulationContext* ctx, TreeNode* root) {
    if (root == NULL) return 0;
    dsa_log_graph(ctx, OP_TREE_VISIT, (uint64_t)root, 0, 0);
    int l = dsa_tree_height(ctx, root->left);
    int r = dsa_tree_height(ctx, root->right);
    return MAX(l, r) + 1;
}

int dsa_tree_diameter(SimulationContext* ctx, TreeNode* root) {
    // Naive O(N^2) visualization for clarity
    if (root == NULL) return 0;
    int l_height = dsa_tree_height(ctx, root->left);
    int r_height = dsa_tree_height(ctx, root->right);
    
    int l_diameter = dsa_tree_diameter(ctx, root->left);
    int r_diameter = dsa_tree_diameter(ctx, root->right);
    
    return MAX(l_height + r_height + 1, MAX(l_diameter, r_diameter));
}
