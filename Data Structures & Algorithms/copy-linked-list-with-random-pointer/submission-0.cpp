/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Maps each original node to its copied node
        unordered_map<Node*, Node*> mp;

        Node* cur = head;

        // First pass:
        // Create a copy of every original node.
        // next and random are not connected yet.
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        // Second pass:
        // Connect the copied nodes using the map.
        while (cur) {
            Node* copy = mp[cur];

            // Copy of original next node
            copy->next = mp[cur->next];

            // Copy of original random node
            copy->random = mp[cur->random];

            cur = cur->next;
        }

        // Return the copy corresponding to the original head
        return mp[head];
    }
};
