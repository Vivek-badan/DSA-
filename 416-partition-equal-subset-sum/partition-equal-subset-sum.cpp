class Solution {
public:

    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){

        // Base Case
        if(target == 0)
            return true;

        if(ind == nums.size())
            return false;

        if(dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = false;
        notTake = f(ind + 1, target, nums, dp);

        bool take = false;

        if(nums[ind] <= target)
            take = f(ind +1, target - nums[ind], nums, dp);

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++)
            sum += nums[i];

        if(sum % 2)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(0, target, nums, dp);
    }
};