class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int max_c=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count=count+1;
               
            }
            else{
                 count=0;
            }

             max_c=max(count,max_c);
           
        }
        return max_c;
        
    }
};