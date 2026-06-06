class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        int ls=0;

        for(int i=0;i<n;i++){
            if(i==0){
                ls=0;
            }
            else{
                ls=ls+nums[i-1];
            }
         int rs=0;
         for(int j=i+1;j<n;j++){
            rs=rs+nums[j];
         }
         
        ans[i] = abs(ls - rs);
        }

        return ans;

        
    }
    
};