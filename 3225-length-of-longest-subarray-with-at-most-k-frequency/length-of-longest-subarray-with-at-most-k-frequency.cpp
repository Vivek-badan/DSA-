class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        int left = 0, max_length = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            // Shrink window if the current element exceeds k frequency
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            // Update max_length
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};
