
#include <stdio.h>
#include "comm.h"

int tree_depth(TreeNode *root) {
    if (NULL == root)  return 0;
    int left_depth = tree_depth(root->left);
    int right_depth = tree_depth(root->right);
    return 1 + (left_depth > right_depth ? left_depth : right_depth);
}

int main(const int argc, const char *argv[])
{
    
    return 0;
}
