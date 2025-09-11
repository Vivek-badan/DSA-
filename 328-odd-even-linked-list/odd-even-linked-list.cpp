class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        vector<int> arr;

        // Step 1: collect odd nodes
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            if (temp->next) temp = temp->next->next;
            else break;
        }

        // Step 2: collect even nodes
        temp = head->next;
        while (temp) {
            arr.push_back(temp->val);
            if (temp->next) temp = temp->next->next;
            else break;
        }

        // Step 3: rewrite linked list
        temp = head;
        int i = 0;
        while (temp) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};
