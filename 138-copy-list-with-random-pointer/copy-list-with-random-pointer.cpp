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
        if (!head) return nullptr;

        // Step 1:insert copy nodes in b/w
        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: connect rndm ptr
        temp = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 3: connect next ptr
        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        temp = head;

        while (temp) {
            copyTail->next = temp->next;
            copyTail = copyTail->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
