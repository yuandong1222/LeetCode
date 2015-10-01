#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        while(root) {
            if (root->left) {
                TreeNode* tail = root->left;
                while (tail->right)
                    tail = tail->right;
                tail->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};
int main(int argc, char** argv) {
    return 0;
}
