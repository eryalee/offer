
#include <stdio.h>
#include <vector>

#include "comm.h"

void preorder(TreeNode *root, std::vector<int> &result) {
    if (NULL == root)  return;
    result.push_back(root->data);
    preorder(root->left);
    preorder(root->right);
}

void preorder_traversal(TreeNode *root, std::vector<int> &result) {
    if (NULL == root)  return;
    std::vector<TreeNode *> node_vec;
    node_vec.push_back(root);
    while (!node_vec.empty()) {
        root = node_vec.back();
        node_vec.pop_back();
        result.push_back(root->data);
        if (root->right != NULL)  node_vec.push_back(root->right);
        if (root->left != NULL)  node_vec.push_back(root->left);
    }
}

int main() {
    TreeNode *root = NULL;
    preorder(root);
    return 0;
}
