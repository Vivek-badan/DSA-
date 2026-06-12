class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, l = 0, r = 0, len = 0, zeroes = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r] == 0)
                zeroes++;
            if (zeroes > k) {
                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            if (zeroes <= k) {
                len = r - l + 1;
                maxlen = max(len, maxlen);
            }
            r++;
        }
        return maxlen;
    }
};