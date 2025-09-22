class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n), rightMin(n), leftMax(n), rightMax(n);
        stack<int> st;

        // Previous smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            leftMin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            rightMin[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Previous greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            leftMax[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            rightMax[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMin = 0, sumMax = 0;
        for (int i = 0; i < n; i++) {
            sumMin += (long long)(i - leftMin[i]) * (rightMin[i] - i) * nums[i];
            sumMax += (long long)(i - leftMax[i]) * (rightMax[i] - i) * nums[i];
        }

        return sumMax - sumMin;
    }
};