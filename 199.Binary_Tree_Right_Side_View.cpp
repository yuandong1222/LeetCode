#include <cstdlib>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    void traverse(TreeNode* node, int depth, vector<int>* result) {
        if (node == NULL) {
            return;
        }

        if (depth < result->size()) {
            (*result)[depth] = node->val;
        } else {
            result->push_back(node->val);
        }

        traverse(node->left, depth + 1, result);
        traverse(node->right, depth + 1, result);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traverse(root, 0, &result);
        return result;
    }
};

int main(int argc, char **argv) {
    return 0;
}
