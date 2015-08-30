#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int traverse(TreeNode* node, int *k) {
        if (node == NULL) return 0;

        int result = traverse(node->left, k);
        if (*k == 0) return result;

        (*k)--;
        if (*k == 0) return node->val;

        result = traverse(node->right, k);
        if (*k == 0) return result;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return traverse(root, &k);
    }
};

int main(int argc, char **argv) {
    return 0;
}
