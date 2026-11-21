class Solution {
public:
    int f(int n ,vector<int>&dp){
        //base case
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int j1=f(n-1,dp);
        int j2=f(n-2,dp);

        return dp[n]=j1 + j2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};