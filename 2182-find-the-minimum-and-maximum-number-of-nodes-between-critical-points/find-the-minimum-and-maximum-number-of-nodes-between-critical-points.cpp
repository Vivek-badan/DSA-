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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;

            // Local maximum or local minimum
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                critical.push_back(index);
            }

            prev = curr;
            curr = next;
            index++;
        }

        // Need at least 2 critical points
        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i - 1]);
        }

        int maxDist = critical.back() - critical.front();

        return {minDist, maxDist};
    }
};