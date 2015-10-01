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
        ListNode fakeHead(-1);
        fakeHead.next = head;

        ListNode *pre = &fakeHead;
        while(head) {
            ListNode *next = head->next;
            if (next == NULL || next->val != head->val) {
                pre = head;
                head = head->next;
                continue;
            }
            
            while (next != NULL && next->val == head->val) {
                head->next = next->next;
                delete next;
                next = head->next;
            }
            pre->next = head->next;
            delete head;
            head = pre->next;
        }
        return fakeHead.next;
    }
};
int main(int argc, char** argv) {
    return 0;
}
