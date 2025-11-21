#include "dsa/trees.h"
#include <limits.h>

static bool validate(SimulationContext* ctx, TreeNode* root, long min, long max) {
    if (root == NULL) return true;
    
    dsa_log_graph(ctx, OP_TREE_VISIT, (uint64_t)root, 0, 0);
    if (root->value <= min || root->value >= max) {
        dsa_log_info(ctx, "BST Violation Found");
        return false;
    }
    return validate(ctx, root->left, min, root->value) &&
           validate(ctx, root->right, root->value, max);
}

bool dsa_bst_validate(SimulationContext* ctx, TreeNode* root) {
    return validate(ctx, root, LONG_MIN, LONG_MAX);
}
