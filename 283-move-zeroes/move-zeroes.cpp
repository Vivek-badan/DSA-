class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Pointer to first zero
        int j = -1;

        // Find first zero
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zero exists
        if (j == -1) return;

        // Rearrange
        for (int i = j + 1; i < nums.size(); i++) {

            if (nums[i] != 0) {

                swap(nums[i], nums[j]);

                // Move j to next zero
                j++;

                // while (j < nums.size() && nums[j] != 0) {
                //     j++;
                // }
            }
        }
    }
};