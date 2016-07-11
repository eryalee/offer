
#include <stdio.h>
#include "comm.h"
int min_depth(TreeNode *root) {
    if (NULL == root) {
        return 0;
    }
    int left_depth = 1 + min_depth(root->left);
    int right_depth = 1 + min_depth(root->right);
    return left_depth < right_depth ? left_depth : right_depth;
}

int main(const int argc, const char *argv[])
{
    TreeNode *root = NULL;
    printf("min depth = %d\n", min_depth(root));
    return 0;
}
