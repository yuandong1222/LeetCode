#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result = head;
        while (head != NULL && head->next != NULL) {
            if (head->next->val == head->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }

        return result;
    }
};
int main(int argc, char** argv) {
    return 0;
}
