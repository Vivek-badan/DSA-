class Solution {
public:
    int sumofdigits(int n){
        int sum=0;
        int org_n=n;
        while(n>0){
            int lstdigit=n%10;
            sum+=lstdigit;
            n/=10;        
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {

        for(int i =0;i<nums.size();i++){
            if(nums[i]<10) {
                if(nums[i]==i){
                    return i;
                }
            }
            else{
                if(sumofdigits(nums[i])==i){
                    return i;
                }
            }
        }
        return -1;
        
    }
};