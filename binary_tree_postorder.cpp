
#include <stdio.h>
#include <vector>

#include "comm.h"

void postorder_recursively(TreeNode* root, std::vector<int>& result) {
    if (NULL == root)   return;
    postorder_recursively(root->left, result);
    postorder_recursively(root->right, result);
    result.push_back(root->data);
}

void postorder_iterator(TreeNode *root, std::vector<int>& result) {
    if (NULL == root)  return;
    std::vector<TreeNode* > nodes_vec;
    nodes_vec.push_back(root);
    while (!nodes_vec.empty()) {
        root = nodes_vec.back();
        nodes_vec.pop_back();
        result.push_back(root->data);
        if (root->left != NULL)  nodes_vec.push_back(root->left);
        if (root->right != NULL)  nodes_vec.push_back(root->right);
    }
    std::reverse(result.begin(), result.end());
}

int main() {
    return 0;
}
