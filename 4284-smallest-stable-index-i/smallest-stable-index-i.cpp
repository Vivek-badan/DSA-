class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxel=INT_MIN;
        
       

        for(int i =0;i<nums.size();i++){
            int minel=INT_MAX;
            maxel=max(maxel,nums[i]);
            for(int j=i;j<nums.size();j++){
                if(nums[j]<minel){
                    minel=nums[j];
                }
            }
            if((maxel-minel)<=k){
                return i;
            }
        }
        return -1;
    }
};