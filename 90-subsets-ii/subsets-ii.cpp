class Solution {
public:

    void solve(int i, vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans){
                //base case
                ans.push_back(ds);
                for(int j=i;j<nums.size();j++){
                    if(j>i && nums[j]==nums[j-1]){
                         continue;
                    }
                    ds.push_back(nums[j]);
                    solve(j+1,nums,ds,ans);
                    ds.pop_back();
                }
               }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>>ans;
        vector<int>ds;

        solve(0,nums,ds,ans);
        return ans;
    }
};