class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at the
        // previous position whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {

            vector<long long> curr(k, 0);

            int x = num % k;

            // Start a new subarray containing only nums[i]
            curr[x]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {

                int newRem = (r * x) % k;

                curr[newRem] += dp[r];
            }

            // Every subarray ending here contributes
            // to the final answer
            for (int r = 0; r < k; r++) {
                ans[r] += curr[r];
            }

            dp = curr;
        }

        return ans;
    }
};