class Solution {
public:
    int f(int i, int j, vector<int>& nums,vector<vector<int>>&dp){

        if(i==j)
            return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];

        int takeLeft = nums[i] - f(i+1,j,nums,dp);

        int takeRight = nums[j] - f(i,j-1,nums,dp);

        return dp[i][j]=max(takeLeft,takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {   vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return f(0,nums.size()-1,nums,dp)>=0;
    }
};