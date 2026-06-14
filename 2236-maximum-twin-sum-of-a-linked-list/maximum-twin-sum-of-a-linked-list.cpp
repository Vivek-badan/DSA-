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
    int pairSum(ListNode* head) {
        // 1. FIND MID

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        // 2. REVERSE 2ND HALF
        ListNode* prev = nullptr;

        while (mid != nullptr) {
            ListNode* nextnode = mid->next;
            mid->next = prev;
            prev = mid; // Missing line
            mid = nextnode;
        }
        // 3.FIND MAX
        int result = 0;
        ListNode* curr = head;
        while (prev != nullptr) {
            result = max(result, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        return result;
    }
};