class Solution {
public:

    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int l = 0;
        int sum = 0;
        int res = 0;
        int r=0;

        while(r<nums.size()){
            sum += nums[r];

            while(sum > goal) {
                sum -= nums[l];
                l++;
            }

            res += (r - l + 1);
            r++;
        }

        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n =nums.size();
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};