#include <stdio.h>
#include <stack>
#include <vector>

#include "comm.h"

void inorder_recursively(TreeNode *root, std::vector<int>& result) {
    if (NULL == root)  return;
    inorder_recursively(root->left, result);
    result.push_back(root->data);
    inorder_recursively(root->right, result);
}

void inorder_iterator(TreeNode* root, std::vector<int>& result) {
    if (NULL == root)  return;
    std::stack<TreeNode *> nodes;
    while (!nodes.empty() || NULL != root) {
        while (NULL != root) {
            nodes.push(root);
            root = root->left;
        }
        root = nodes.top();
        nodes.pop();
        result.push_back(root->data);
        root = root->right;
    }
    return;
}


int main() {
    return 0;
}
