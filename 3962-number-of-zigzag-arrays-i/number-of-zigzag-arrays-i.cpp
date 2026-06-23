class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 1), down(m, 1);

        for (int len = 1; len < n; len++) {
            vector<long long> nxtUp(m), nxtDown(m);

            long long s = 0;
            for (int i = m - 2; i >= 0; --i) {
                s = (s + down[i + 1]) % MOD;
                nxtUp[i] = s;
            }

            s = 0;
            for (int i = 1; i < m; ++i) {
                s = (s + up[i - 1]) % MOD;
                nxtDown[i] = s;
            }

            up = move(nxtUp);
            down = move(nxtDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};