#include "dsa/trees.h"
#include <stdlib.h>

TreeNode* dsa_tree_create_node(SimulationContext* ctx, int32_t value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    dsa_log_graph(ctx, OP_ALLOC, (uint64_t)node, 0, value);
    return node;
}
