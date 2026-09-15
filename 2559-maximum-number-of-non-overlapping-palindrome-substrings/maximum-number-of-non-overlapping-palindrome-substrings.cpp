class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // palindrome[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        palindrome[i][j] = true;
                    }
                    else {
                        palindrome[i][j] = palindrome[i + 1][j - 1];
                    }
                }
            }
        }

        // dp[i] = maximum palindromes we can take
        // using s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Option 1: skip current character
            dp[i] = dp[i - 1];

            // Option 2: take a palindrome ending at i-1
            for (int j = 0; j <= i - k; j++) {

                int len = i - j;

                if (len >= k && palindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};