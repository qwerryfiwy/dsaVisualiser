#include "dsa/trees.h"
#include <stdlib.h>

TreeNode* dsa_bst_insert(SimulationContext* ctx, TreeNode* root, int32_t value) {
    if (root == NULL) {
        return dsa_tree_create_node(ctx, value);
    }

    dsa_log_graph(ctx, OP_TREE_COMPARE, (uint64_t)root, 0, value);
    
    if (value < root->value) {
        root->left = dsa_bst_insert(ctx, root->left, value);
        dsa_log_tree(ctx, OP_TREE_LINK_LEFT, (uint64_t)root, (int32_t)(uint64_t)root->left); // Visual Link
    } else if (value > root->value) {
        root->right = dsa_bst_insert(ctx, root->right, value);
        dsa_log_tree(ctx, OP_TREE_LINK_RIGHT, (uint64_t)root, (int32_t)(uint64_t)root->right); // Visual Link
    }
    return root;
}

TreeNode* dsa_bst_search(SimulationContext* ctx, TreeNode* root, int32_t value) {
    if (root == NULL || root->value == value) {
        if (root) dsa_log_graph(ctx, OP_ARR_HIGHLIGHT, (uint64_t)root, 0, value);
        return root;
    }
    
    dsa_log_graph(ctx, OP_TREE_COMPARE, (uint64_t)root, 0, value);
    if (value < root->value) return dsa_bst_search(ctx, root->left, value);
    return dsa_bst_search(ctx, root->right, value);
}

// Helper for Delete
static TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

TreeNode* dsa_bst_delete(SimulationContext* ctx, TreeNode* root, int32_t value) {
    if (root == NULL) return root;

    dsa_log_graph(ctx, OP_TREE_COMPARE, (uint64_t)root, 0, value);

    if (value < root->value) {
        root->left = dsa_bst_delete(ctx, root->left, value);
    } else if (value > root->value) {
        root->right = dsa_bst_delete(ctx, root->right, value);
    } else {
        // Node Found
        dsa_log_info(ctx, "Deleting Node");
        
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            dsa_log_graph(ctx, OP_FREE, (uint64_t)root, 0, 0);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            dsa_log_graph(ctx, OP_FREE, (uint64_t)root, 0, 0);
            free(root);
            return temp;
        }
        // Two children: Get Successor
        TreeNode* temp = min_value_node(root->right);
        root->value = temp->value; 
        dsa_log_graph(ctx, OP_ARR_WRITE, (uint64_t)root, 0, temp->value); // Visual update
        root->right = dsa_bst_delete(ctx, root->right, temp->value);
    }
    return root;
}
