/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode*collisionpt(ListNode * t1, ListNode * t2, int d) {
            while (d) {
                d--;
                t2 = t2->next;
            }
            while (t1 != t2) {
                t1 = t1->next;
                t2 = t2->next;
            }
            return t1;
        }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* t1 = headA;
        int n1 = 0;
        while (t1 != nullptr) {
            n1++;
            t1 = t1->next;
        }
        ListNode* t2 = headB;
        int n2 = 0;
        while (t2 != nullptr) {
            n2++;
            t2 = t2->next;
        }
        if (n1 < n2) {
            return collisionpt(headA, headB, n2 - n1);
        }
        return collisionpt(headB, headA, n1 - n2);
    }
};