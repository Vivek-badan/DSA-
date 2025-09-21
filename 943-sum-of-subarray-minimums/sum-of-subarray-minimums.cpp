class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // previous strictly smaller element distance
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next smaller or equal element distance
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total = (total + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        return (int)total;
    }
};
