class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans(2,-1);
        for(int i=0;i<n;i++){
            if(target==nums[i]){
                if(ans[0]==-1)ans[0]=i;
                ans[1]=i;
            }
        }
        return ans;
        
    }
};