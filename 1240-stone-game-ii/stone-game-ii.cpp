class Solution {
public:

    int f(int i, int M, vector<int>& piles, int n,vector<vector<int>>&dp) {

        // If all piles are taken
        if (i >= n) return 0;
        if(dp[i][M]!=-1) return dp[i][M];

        int maxi = 0;
        int stones = 0;

        // Take X piles, where X <= 2*M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            stones += piles[i + X - 1];

            // Opponent gets to play from i + X
            // New M = max(M, X)
            int opponent = f(i + X, max(M, X), piles, n,dp);

            // Total stones Alice can get:
            // stones taken now + remaining stones - opponent's best
            int totalRemaining = 0;
            for (int j = i; j < n; j++)
                totalRemaining += piles[j];

            maxi = max(maxi, totalRemaining - opponent);
        }

        return dp[i][M]=maxi;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));           
        return f(0, 1, piles, n,dp);
    }
};