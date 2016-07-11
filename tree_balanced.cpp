
#include <stdio.h>
#include "comm.h"

bool is_balanced(TreeNode *root, int& depth) {
    if (NULL == root) {
        depth = 0;
        return true;
    }
    int left_depth = 0;
    int right_depth = 0;
    if (is_balanced(root->left, left_depth) && is_balanced(root->right, right_depth)) {
        if (left_depth - right_depth > 1 || right_depth - left_depth > 1) {
            return false;
        }
        depth = 1 + (left_depth > right_depth ? left_depth : right_depth);
        return true;
    }
    return false;
}

int main(const int argc, const char *argv[])
{
    
    return 0;
}


