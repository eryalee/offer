

#include <stdio.h>
#include <new>
#include "comm.h"

TreeNode *construct_core(int *start_preorder, int *end_preorder, int* start_inorder, int *end_inorder) {
    int root_value = *start_preorder;
    TreeNode *p_root = new (std::nothrow) TreeNode();
    if (NULL == p_root)  throw "new treenode failed.";

    p_root->data = root_value;
    p_root->left = p_root->right = NULL;
    if (start_preorder == end_preorder) {
        if (start_inorder == end_inorder &&
            *start_preorder == *start_inorder) {
            return p_root;
        } else {
            throw "invalid tree";
        }
    }

    //
    int *root_inorder = start_inorder;
    while (root_inorder != NULL && *root_inorder != root_value)  root_inorder++;

    if (end_inorder == root_inorder && *root_inorder != root_value) {
        throw "invalid tree";
    }

    int left_len = root_inorder - start_inorder;
    int *left_preorder_end = start_preorder + left_len;
    if (left_len > 0) {
        p_root->left = construct_core(start_preorder + 1, left_preorder_end, start_inorder, root_inorder - 1);
    }
    if (left_len < end_preorder - start_preorder) {
        p_root->right = construct_core(left_preorder_end + 1, end_preorder, root_inorder + 1, end_inorder);
    }


    return p_root;
}

TreeNode *construct_binary_tree(int *preorder, int *inorder, int len) {
    if (NULL == preorder || NULL == inorder || len <= 0)  return NULL;
    return construct_core(preorder, preorder + len - 1, inorder, inorder + len - 1);
}

int main() {
    return 0;
}
