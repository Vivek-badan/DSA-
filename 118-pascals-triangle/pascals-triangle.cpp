class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int n = 0; n < numRows; n++) {
            vector<int> row;
            long long val = 1;
            for (int r = 0; r <= n; r++) {
                if (r == 0) {
                    val = 1;
                } else {
                    val = val * (n - r + 1) / r;
                }
                row.push_back(val);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
