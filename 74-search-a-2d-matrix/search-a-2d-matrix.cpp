class Solution {
public:
    bool BS(vector<int>& row, int target) {
        int low = 0;
        int n = row.size();
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] > target)
                high = mid - 1;
            else if (row[mid] < target)
                low = mid + 1;
            else
                return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                return BS(matrix[i], target);
            }
        }
        return false;
    }
};
