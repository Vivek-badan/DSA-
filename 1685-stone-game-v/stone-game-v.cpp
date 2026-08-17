class Solution {
public:

    int f(int i, int j, vector<int>& prefix, vector<vector<int>>& dp) {

        // Only one pile -> cannot split
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        // Split between k and k+1
        for(int k = i; k < j; k++) {

            int left = prefix[k + 1] - prefix[i];
            int right = prefix[j + 1] - prefix[k + 1];

            if(left < right) {

                // Bob keeps left
                maxi = max(maxi,
                    left + f(i, k, prefix, dp)
                );

            }
            else if(right < left) {

                // Bob keeps right
                maxi = max(maxi,
                    right + f(k + 1, j, prefix, dp)
                );

            }
            else {

                // Equal -> Alice can choose either
                maxi = max(maxi,
                    max(
                        left + f(i, k, prefix, dp),
                        right + f(k + 1, j, prefix, dp)
                    )
                );
            }
        }

        return dp[i][j] = maxi;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n - 1, prefix, dp);
    }
};