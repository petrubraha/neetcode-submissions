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
        unordered_map<Node*, Node*> seen;
        seen[nullptr] = nullptr;
        Node* iter = head;
        while (iter) {
            if (seen.find(iter) == seen.end()) {
                seen[iter] = new Node(iter->val);
            }
            if (seen.find(iter->next) == seen.end()) {
                seen[iter->next] = new Node(iter->next->val);
            }
            if (seen.find(iter->random) == seen.end()) {
                seen[iter->random] = new Node(iter->random->val);
            }
            seen[iter]->next = seen[iter->next];
            seen[iter]->random = seen[iter->random];
            iter = iter->next;
        }
        return seen[head];
    }
};
