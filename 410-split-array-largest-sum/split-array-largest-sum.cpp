class Solution {
public:
    int maxElement(vector<int>& nums) {
        int maxii = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (maxii < nums[i])
                maxii = nums[i];
        }
        return maxii;
    }

    int sumOfArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }

    int countOfStudents(vector<int>& nums, int mid) {
        int student = 1;
        long long pageStudent = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pageStudent + nums[i] <= mid) {
                pageStudent += nums[i];
            } else {
                student++;
                pageStudent = nums[i];
            }
        }
        return student;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = maxElement(nums);
        int high = sumOfArray(nums);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int noOfStudent = countOfStudents(nums, mid);

            if (noOfStudent > k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};
