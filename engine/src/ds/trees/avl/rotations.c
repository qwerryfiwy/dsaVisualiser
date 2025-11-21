#include "dsa/trees.h"
#define MAX(a,b) ((a) > (b) ? (a) : (b))

static int height(TreeNode *N) {
    if (N == NULL) return 0;
    return N->height;
}

TreeNode* rightRotate(SimulationContext* ctx, TreeNode* y) {
    dsa_log_tree(ctx, OP_TREE_ROTATE_RIGHT, (uint64_t)y, 0);
    
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = MAX(height(y->left), height(y->right)) + 1;
    x->height = MAX(height(x->left), height(x->right)) + 1;

    // Visual Link Updates
    dsa_log_tree(ctx, OP_TREE_LINK_RIGHT, (uint64_t)x, (int32_t)(uint64_t)y);
    dsa_log_tree(ctx, OP_TREE_LINK_LEFT, (uint64_t)y, (int32_t)(uint64_t)T2);

    return x;
}

TreeNode* leftRotate(SimulationContext* ctx, TreeNode* x) {
    dsa_log_tree(ctx, OP_TREE_ROTATE_LEFT, (uint64_t)x, 0);

    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = MAX(height(x->left), height(x->right)) + 1;
    y->height = MAX(height(y->left), height(y->right)) + 1;

    dsa_log_tree(ctx, OP_TREE_LINK_LEFT, (uint64_t)y, (int32_t)(uint64_t)x);
    dsa_log_tree(ctx, OP_TREE_LINK_RIGHT, (uint64_t)x, (int32_t)(uint64_t)T2);

    return y;
}
