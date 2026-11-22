class Solution {
public:
    int f(int i, int j, string& text1, string& text2,
          vector<vector<int>>& dp) {

        // Base case
        if(i == text1.size() || j == text2.size())
            return 0;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Matching characters
        if(text1[i] == text2[j]) {
            return dp[i][j] =
                1 + f(i+1, j+1, text1, text2, dp);
        }

        // Non-matching characters
        return dp[i][j] = max(
            f(i+1, j, text1, text2, dp),
            f(i, j+1, text1, text2, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(0, 0, text1, text2, dp);
    }
};