class Solution {
public:
    ListNode* getkthnode(ListNode* temp, int k) {
        while (temp != nullptr && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverselinkedlist(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevlast = dummy;
        ListNode* temp = head;

        while (temp != nullptr) {
            ListNode* kthnode = getkthnode(temp, k);
            if (kthnode == nullptr) {
                prevlast->next = temp;
                break;
            }

            ListNode* nextnode = kthnode->next;
            kthnode->next = nullptr;

            ListNode* newhead = reverselinkedlist(temp);

            prevlast->next = newhead;
            temp->next = nextnode;

            prevlast = temp;
            temp = nextnode;
        }

        return dummy->next;
    }
};
