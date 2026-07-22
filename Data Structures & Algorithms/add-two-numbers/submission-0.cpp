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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // dummy node
        ListNode* cur = dummy; // refer to the current insertion position
        int total = 0;
        int carry = 0;

        while (l1 || l2 || carry) {
            total = carry; // start with carry

            if (l1) {
                total += l1->val; // add digit from l1
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val; // add digit from l2
                l2 = l2->next;
            }
            int num = total % 10; // current digit
            carry = total / 10;

            dummy->next = new ListNode(num); // create new node to store result digit
            dummy = dummy->next; // move forward 
        }
        ListNode* res = cur->next; // actual result start from res->next not dummy node

        delete cur; // save memory

        return res;        
    }
};
