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
        if (head == NULL) return NULL;
        if (head->next == NULL || head->next->val != head->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }

        int value = head->val;
        ListNode* next = head->next;
        while (next != NULL && next->val == value) {
            delete head;
            head = next;
            next = head->next;
        }
        delete head;
        return deleteDuplicates(next);
    }
};
int main(int argc, char** argv) {
    return 0;
}
