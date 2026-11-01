
class Solution {
public:
    void solve(vector<int>& nums,
               vector<int>& ds,
               vector<int>& vis,
               vector<vector<int>>& ans) {

        // Correct base case
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (vis[i] == 0) {

                // Mark visited
                vis[i] = 1;

                // Pick
                ds.push_back(nums[i]);

                // Recursive call
                solve(nums, ds, vis, ans);

                // Backtrack
                ds.pop_back();

                // Mark unvisited
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(nums.size(), 0);

        solve(nums, ds, vis, ans);

        return ans;
    }
};
