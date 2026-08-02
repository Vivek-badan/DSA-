class Solution {
public:
    int f(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int AliceTakesFirst = piles[i] - f(i + 1, j, piles, dp);

        int AliceTakesSecond = piles[j] - f(i, j - 1, piles, dp);

        return dp[i][j] = max(AliceTakesFirst, AliceTakesSecond);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n , vector<int>(n, 0));
        // base case
        for(int i = 0; i < n; i++){
             dp[i][i] = piles[i];
        }
   

        // bottom up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                
                int AliceTakesFirst = piles[i] - dp[i + 1][j];

                int AliceTakesSecond = piles[j] - dp[i][j-1];
               
                dp[i][j] = max(AliceTakesFirst, AliceTakesSecond);

                
            }

        }
       return dp[0][n - 1] > 0;
    }
};