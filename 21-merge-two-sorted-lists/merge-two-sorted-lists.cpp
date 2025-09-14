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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val < t2->val) {
                cur->next = t1;
                t1 = t1->next;
            } else {
                cur->next = t2;
                t2 = t2->next;
            }
            cur = cur->next;
        }

        if (t1 != nullptr)
            cur->next = t1;
        else
            cur->next = t2;

        return dummy->next;
    }
};