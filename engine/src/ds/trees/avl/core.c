#include "dsa/trees.h"
#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Prototypes from rotations.c (assume linking works)
TreeNode* rightRotate(SimulationContext* ctx, TreeNode* y);
TreeNode* leftRotate(SimulationContext* ctx, TreeNode* x);
static int height(TreeNode *N) { return N ? N->height : 0; }
static int getBalance(TreeNode *N) { return N ? height(N->left) - height(N->right) : 0; }

TreeNode* dsa_avl_insert(SimulationContext* ctx, TreeNode* node, int32_t value) {
    if (node == NULL) return dsa_tree_create_node(ctx, value);

    if (value < node->value)
        node->left = dsa_avl_insert(ctx, node->left, value);
    else if (value > node->value)
        node->right = dsa_avl_insert(ctx, node->right, value);
    else
        return node; // Duplicate keys not allowed

    node->height = 1 + MAX(height(node->left), height(node->right));
    dsa_log_tree(ctx, OP_TREE_SET_HEIGHT, (uint64_t)node, node->height);

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && value < node->left->value)
        return rightRotate(ctx, node);

    // Right Right
    if (balance < -1 && value > node->right->value)
        return leftRotate(ctx, node);

    // Left Right
    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(ctx, node->left);
        return rightRotate(ctx, node);
    }

    // Right Left
    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(ctx, node->right);
        return leftRotate(ctx, node);
    }

    return node;
}
