class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        int total = n * m;
        k %= total;

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // Current 1D index
                int idx = i * m + j;

                // New 1D index after shift
                int newIdx = (idx + k) % total;

                // Convert back to 2D
                int newRow = newIdx / m;
                int newCol = newIdx % m;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};