class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int maxi= INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cond = (nums[i] - 1) * (nums[j] - 1);
                if(maxi<cond){
                    maxi=cond;
                }
            }
        }
        return maxi;

    }
};