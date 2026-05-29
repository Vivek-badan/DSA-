class Solution {
public:
    int digitsum(int n) {
        int sum1 = 0;
        while (n > 0) {
            sum1 += n % 10;
            n = n / 10;
        }
        return sum1;
    }

    int minElement(vector<int>& nums) {
        int mini= INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int sum = digitsum(nums[i]);
            mini=min(mini,sum);

        }
        return mini;
    }
};