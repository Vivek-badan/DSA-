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

        stack<int>st;
        ListNode *curr=head;
        while(curr!=nullptr){
            st.push(curr->val);
            curr=curr->next;
        }

        int n=st.size();
        curr=head;
        int cnt=1;
        int res=0;
        while(cnt<=n/2){
            res=max(res,curr->val+st.top());
            curr=curr->next;
            st.pop();
            cnt++;
        }
        return res++;
        

 
    }
};