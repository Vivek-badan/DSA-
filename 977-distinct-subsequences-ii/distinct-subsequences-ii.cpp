class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();

        // dp[i] = number of distinct non-empty subsequences
        // using first i characters
        vector<long long> dp(n + 1, 0);

        // last occurrence of every character
        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a';

            // All previous subsequences:
            // 1. don't take current char
            // 2. take current char
            // + current char alone
            dp[i] = (2LL * dp[i - 1] + 1) % mod;

            // Remove duplicated subsequences
            if (last[ch] != -1) {
                int prev = last[ch];

                dp[i] = (dp[i] - (dp[prev] + 1) + mod) % mod;
            }

            // Store 0-based index
            last[ch] = i - 1;
        }

        return dp[n];
    }
};