class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummynode = new ListNode(-1);
        ListNode* curr = dummynode;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;

        while (t1 != nullptr || t2 != nullptr) {
            int sum = carry;
            if (t1) sum += t1->val;
            if (t2) sum += t2->val;

            ListNode* newnode;  
            if (sum >= 10) {
                newnode = new ListNode(sum % 10);
                carry = 1;
            } else {
                newnode = new ListNode(sum);
                carry = 0;
            }

            curr->next = newnode;
            curr = curr->next;

            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }

        if (carry) {
            ListNode* newnode = new ListNode(1);  
            curr->next = newnode;
        }

        return dummynode->next;  
    }
};
