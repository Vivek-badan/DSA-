class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;

            for (int num : nums)
                sum += (num + mid - 1) / mid;  // same as ceil(num / mid)

            if (sum <= threshold) {
                ans = mid;         // possible answer
                high = mid - 1;    // try smaller divisor
            } else {
                low = mid + 1;     // need larger divisor
            }
        }

        return ans;
    }
};
