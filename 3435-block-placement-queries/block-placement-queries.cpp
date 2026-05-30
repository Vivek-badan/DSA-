class FenwickTree {
public:
    vector<int> bit;

    FenwickTree(int n) {
        bit.resize(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] = max(bit[idx], val);
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int ans = 0;

        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= idx & (-idx);
        }

        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int limit = min(50000, (int)queries.size() * 3);

        FenwickTree ft(limit + 1);

        set<int> obstacles{0, limit};

        vector<bool> ans;

        // Add all obstacles first
        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        // Build initial gaps
        for (auto it = obstacles.begin();
             next(it) != obstacles.end();
             ++it) {

            int left = *it;
            int right = *next(it);

            ft.update(right, right - left);
        }

        // Process in reverse
        for (int i = queries.size() - 1; i >= 0; i--) {

            int type = queries[i][0];
            int x = queries[i][1];

            if (type == 1) {

                auto it = obstacles.find(x);

                int prevPos = *prev(it);

                if (next(it) != obstacles.end()) {

                    int nextPos = *next(it);

                    ft.update(nextPos, nextPos - prevPos);
                }

                obstacles.erase(it);
            }

            else {

                int sz = queries[i][2];

                auto it = obstacles.upper_bound(x);

                int prevObstacle = *prev(it);

                bool possible =
                    ft.query(prevObstacle) >= sz ||
                    (x - prevObstacle) >= sz;

                ans.push_back(possible);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};