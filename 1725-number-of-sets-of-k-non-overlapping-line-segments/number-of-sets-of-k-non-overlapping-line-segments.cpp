class Solution {
public:
    const int MOD = 1e9 + 7;

    int n;
    vector<vector<vector<int>>> dp;

    int solve(int i, int k, int started) {

        // All required segments completed
        if (k == 0) {
            return 1;
        }

        // No more points
        if (i == n) {
            return 0;
        }

        if (dp[i][k][started] != -1) {
            return dp[i][k][started];
        }

        long long ans = 0;

        if (started == 0) {

            // Option 1: Don't start a segment at i
            ans += solve(i + 1, k, 0);

            // Option 2: Start a segment at i
            ans += solve(i + 1, k, 1);
        }
        else {

            // Option 1: Keep the current segment open
            ans += solve(i + 1, k, 1);

            // Option 2: End current segment at i
            //
            // Notice i instead of i+1:
            // another segment can start at the same endpoint.
            ans += solve(i, k - 1, 0);
        }

        return dp[i][k][started] = ans % MOD;
    }

    int numberOfSets(int N, int k) {

        n = N;

        dp.assign(
            n + 1,
            vector<vector<int>>(
                k + 1,
                vector<int>(2, -1)
            )
        );

        return solve(0, k, 0);
    }
};