class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int rs = 0;
        for (int x : nums) {
            rs += x;
        }

        int ls = 0;

        for (int i = 0; i < n; i++) {
            rs -= nums[i];          // right sum excluding current element
            ans[i] = abs(ls - rs);
            ls += nums[i];          // update left sum
        }

        return ans;
    }
};