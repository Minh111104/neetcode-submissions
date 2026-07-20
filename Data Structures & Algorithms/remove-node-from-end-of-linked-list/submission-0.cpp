/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while (n > 0) {
            right = right->next; // move right ahead by n steps
            n--;
        }

        while (right) { // left is exactly before the node that must be removed
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next; // skip the wanted node

        return dummy->next;
    }
};
