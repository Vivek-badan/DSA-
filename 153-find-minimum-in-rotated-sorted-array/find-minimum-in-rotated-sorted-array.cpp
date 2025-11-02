class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[start] < nums[end]) {
                mini = min(mini, nums[start]);
                break;
            }

            // left sorted
            if (nums[start] <= nums[mid]) {
                mini = min(mini, nums[start]);
                start = mid + 1;
            }
            // right unsorted
            else {
                mini = min(mini, nums[mid]);
                end = mid - 1;  // ✅ fixed here
            }
        }

        return mini;
    }
};
