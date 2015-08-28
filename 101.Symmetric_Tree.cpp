#include <vector>
#include <iostream>
#include <cstdlib>

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
    bool isSymmetric(TreeNode *root) {
        //return _isSymmetricByLine(root);
        return _isSymmetricTreeByRecursion(root);
    }

    bool _isSymmetricByLine(TreeNode * root) {
        int line_size = 1;
        TreeNode **line = (TreeNode **)malloc(sizeof(TreeNode *));
        line[0] = root;
        
        while (!_isEmptyLine(line, line_size)) {
            TreeNode **next_line = (TreeNode **)malloc(sizeof(TreeNode *) * line_size * 2);
            for (int i = 0; i < line_size; i++) {
                TreeNode* node = line[i];
                if (node == NULL) {
                    next_line[i * 2] = NULL;
                    next_line[i * 2 + 1] = NULL;
                }
                else {
                    next_line[i * 2] = node->left;
                    next_line[i * 2 + 1] = node->right;
                }
            }
            
            free(line);
            line = next_line;
            line_size *= 2;
            
            if (!_isSymmetricLine(line, line_size)) {
                free(line);
                return false;
            }
        }
        free(line);
        return true;
    }
    bool _isSymmetricLine(TreeNode ** line, int line_size) {
        for (int i = 0; i <= line_size / 2; i++) {
            TreeNode* head = line[i];
            TreeNode* tail = line[line_size - i - 1];
            
            if (head != NULL && tail == NULL) {
                return false;
            }
            
            if (head == NULL && tail != NULL) {
                return false;
            }
            
            if (head == NULL && tail == NULL) {
                continue;
            }
            
            if (head->val != tail->val) {
                return false;
            }
        }
        return true;
    }
    bool _isEmptyLine(TreeNode ** line, int line_size) {
        for (int i = 0; i < line_size; i++) {
            if (line[i] != NULL) {
                return false;
            }
        }
        return true;
    }
    
    bool _isSymmetricTreeByRecursion(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        
        return _isSymmetricTreeByRecursion_Node(root->left, root->right);
    }
    
    bool _isSymmetricTreeByRecursion_Node(TreeNode* left, TreeNode* right) {
        //Both is NULL
        if (left == NULL && right == NULL) {
            return true;
        }
        //one is NULL while another is NOT NULL
        if (left == NULL || right == NULL) {
            return false;
        }
        //Both is NOT NULL
        if (left->val != right->val) {
            return false;
        }
        
        if (!_isSymmetricTreeByRecursion_Node(left->left, right->right)) {
            return false;
        }
        if (!_isSymmetricTreeByRecursion_Node(left->right, right->left)) {
            return false;
        }
        
        return true;
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
    
        cout << solution.isSymmetric(&n1) << endl;
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
    
        cout << solution.isSymmetric(&n1) << endl;
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
        
        cout << solution.isSymmetric(&n1) << endl;
    };
    void test_case_4() {
        Solution solution;
        
        TreeNode n1(1);
        TreeNode n2(2);
    
        n1.left = &n2;
    
        cout << solution.isSymmetric(&n1) << endl;
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
