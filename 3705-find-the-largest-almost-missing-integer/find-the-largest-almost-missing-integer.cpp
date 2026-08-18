class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        int n = nums.size();

        for(int i = 0; i <= n - k; i++) {

            unordered_set<int> st;

            // Current subarray of size k
            for(int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this window only once for each number
            for(int x : st) {
                freq[x]++;
            }
        }

        int ans = -1;

        for(auto it : freq) {
            if(it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};