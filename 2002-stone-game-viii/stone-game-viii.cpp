class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();

        // Step 1: Prefix Sum
        for(int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Step 2: Take all stones initially
        int dp = stones[n - 1];

        // Step 3: DP from right to left
        for(int i = n - 2; i > 0; i--) {

            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};