class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int l = 0, count = 0, odds = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) odds++;
            while (odds > k) {
                if (nums[l] % 2 != 0) odds--;
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
};
