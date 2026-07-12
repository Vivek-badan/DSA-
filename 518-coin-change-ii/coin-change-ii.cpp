class Solution {
public:

    int f(int index , int amount , vector<int>& coins,vector<vector<int>>&dp){

        //base case
        if(index==0){
            if(amount% coins[0]==0) return 1;
            return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        //recursive 
        long not_take=f(index-1,amount,coins,dp);

        long take=0;
        if(coins[index]<=amount) take =f(index,amount-coins[index],coins,dp);

          return dp[index][amount]=take + not_take;

    }
    int change(int amount, vector<int>& coins) {
        
        int n =coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};