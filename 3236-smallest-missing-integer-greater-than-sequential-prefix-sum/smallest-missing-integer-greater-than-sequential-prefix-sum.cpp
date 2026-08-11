class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find sequential prefix sum
        int sum = nums[0];

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        // Step 2: Store all elements in a set
        unordered_set<int> st;

        for(int x : nums) {
            st.insert(x);
        }

        // Step 3: Find smallest missing integer >= sum
        while(st.find(sum) != st.end()) {
            sum++;
        }

        return sum;
    }
};