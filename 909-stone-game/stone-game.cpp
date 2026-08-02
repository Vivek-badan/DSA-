class Solution {
public:

    int f(int i , int j , vector<int>& piles , vector<vector<int>>&dp){
       if(i > j)
            return 0;

        if(i == j)
            return piles[i];
        
        if(dp[i][j]!=-1) return dp[i][j];

        int AliceTakesFirst = piles[i]-f(i+1,j,piles,dp);

        int AliceTakesSecond= piles[j]-f(i,j-1,piles,dp);

        return dp[i][j]=max(AliceTakesFirst , AliceTakesSecond) ;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return f(0,n-1,piles,dp)>0;
        
    }
};