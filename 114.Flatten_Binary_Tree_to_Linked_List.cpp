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
    TreeNode* _traverse(TreeNode* node, TreeNode* head) {
        if (node == NULL) return head;

        head = _traverse(node->right, head);
        head = _traverse(node->left, head);
        node->right = head;
        node->left = NULL;
        head = node;
        return head;
    }
public:
    void flatten(TreeNode* root) {
        _traverse(root, NULL);
    }
};
int main(int argc, char** argv) {
    return 0;
}
