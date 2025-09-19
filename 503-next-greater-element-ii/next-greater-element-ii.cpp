class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for(int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while(!st.empty() && nums[st.top()] < nums[idx]) {
                nge[st.top()] = nums[idx];
                st.pop();
            }
            if(i < n) st.push(idx);
        }

        return nge;
    }
};
