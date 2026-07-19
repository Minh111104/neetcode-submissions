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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }

        // Step 1: Find the middle of the linked list
        // slow moves 1 step, fast moves 2 steps
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'slow' is now at the middle
        // Second half starts after slow
        ListNode* second = slow->next;

        // Split the list into two halves
        slow->next = nullptr;

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;

        while (second) {
            ListNode* temp = second->next;

            second->next = prev;
            prev = second;
            second = temp;
        }

        // After reversing:
        // prev points to the head of the reversed second half

        // Step 3: Merge the two halves alternately
        ListNode* first = head;
        second = prev;

        while (second) {
            // Save the next nodes
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // Insert one node from second half
            first->next = second;
            second->next = temp1;

            // Move to the next nodes
            first = temp1;
            second = temp2;
        }
    }
};
