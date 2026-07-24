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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (true) {
            int minList = -1;

            // Find the list whose current head has the smallest value
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) {
                    continue;
                }

                if (minList == -1 || lists[i]->val < lists[minList]->val) {
                    minList = i;
                }
            }

            // All lists are empty
            if (minList == -1) {
                break;
            }

            // Attach the smallest current node
            cur->next = lists[minList];
            cur = cur->next;

            // Move that list's head forward
            lists[minList] = lists[minList]->next;
        }
        return dummy.next;        
    }
};
