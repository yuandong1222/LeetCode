#include <queue>
#include <iostream>

using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //return _maxDepth_Recursion(root);
        return _maxDepth_Iteration(root);
    }
    int _maxDepth_Recursion(TreeNode* root) {
        return _maxDepth_Recursion(root, 0);
    }
    int _maxDepth_Recursion(TreeNode* root, int current_depth) {
        if (root == NULL) {
            return 0;
        }
        
        int left_depth = _maxDepth_Recursion(root->left, current_depth);
        int right_depth = _maxDepth_Recursion(root->right, current_depth);
        
        int max_depth = left_depth > right_depth ? left_depth : right_depth;
        
        return max_depth + 1;
    }
    
    int _maxDepth_Iteration(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int max_depth = 1;
        queue<pair<TreeNode*, int> > queue;
        queue.push(pair<TreeNode*, int>(root, 1));
        
        while (!queue.empty()) {
            pair<TreeNode*, int> node = queue.front();
            queue.pop();
            
            if (node.second > max_depth) {
                max_depth = node.second;
            }
            
            if(node.first->left != NULL) {
                queue.push(pair<TreeNode*, int>(node.first->left, node.second + 1));
            }
            if(node.first->right != NULL) {
                queue.push(pair<TreeNode*, int>(node.first->right, node.second + 1));
            }
        }
        
        return max_depth;
    }
};


class Solution_Test {
public:
    void test_case_1() {
        Solution solution;
        
        TreeNode n1(1);
        
        TreeNode n2(2);
        TreeNode n3(2);
        n1.left = &n2;
        n1.right = &n3;
        
        TreeNode n4(3);
        TreeNode n5(4);
        n2.left = &n4;
        n2.right = &n5;
        
        TreeNode n6(3);
        TreeNode n7(4);
        n3.left = &n7;
        n3.right = &n6;
        
        cout << solution.maxDepth(&n1) << endl;
    };
    void test_case_2() {
        Solution solution;
        
        TreeNode n1(1);
        
        TreeNode n2(2);
        TreeNode n3(2);
        n1.left = &n2;
        n1.right = &n3;
        
        TreeNode n4(3);
        n2.right = &n4;
        
        TreeNode n6(3);
        n3.right = &n6;
        
        cout << solution.maxDepth(&n1) << endl;
    };
    void test_case_3() {
        Solution solution;
        
        TreeNode n1(1);
        TreeNode n2(-42);
        TreeNode n3(-42);
        TreeNode n4(76);
        TreeNode n5(76);
        TreeNode n6(13);
        TreeNode n7(13);
        
        n1.left = &n2;
        n1.right = &n3;
        n2.right = &n4;
        n3.left = &n5;
        n4.right = &n6;
        n5.right = &n7;
        
        cout << solution.maxDepth(&n1) << endl;
    };
    void test_case_4() {
        Solution solution;
        
        TreeNode n1(1);
        TreeNode n2(2);
        
        n1.left = &n2;
        
        cout << solution.maxDepth(&n1) << endl;
    };
};
int main(int argc, char* argv[]) {
    Solution_Test solution_test;
    solution_test.test_case_1();
    solution_test.test_case_2();
    solution_test.test_case_3();
    solution_test.test_case_4();
    
    return 0;
};
