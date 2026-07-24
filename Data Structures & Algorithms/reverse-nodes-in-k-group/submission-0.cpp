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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0, head); // default val of dummy node as 0, next pointer is set to head  
        ListNode* groupPrev = &dummy; // keep track of the first node

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k); // last node in the group
            
            // kth node in the last group is not big enough to reverse
            if (kth == nullptr) {
                break;
            }
            ListNode* groupNext = kth->next;   // keep track of the next node after reversing each group

            // reverse nodes in each group
            ListNode* prev = nullptr;  // connect each group of linked list together
            ListNode* curr = groupPrev->next;         // first node in the group

            while (curr != groupNext) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            ListNode* temp = groupPrev->next;  // store temp as the first node in the group
            groupPrev->next = kth;       // now groupPrev->next is the last node in the group
            temp->next = groupNext;       // reconnect the first node of the group to the next node after reversing
            // reset for the next loop
            groupPrev = temp;           // now groupPrev is the last node in the group
        }

        return dummy.next;
    }

    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k -= 1;
        }
        return curr;    // curr = Kth node
    }
};
