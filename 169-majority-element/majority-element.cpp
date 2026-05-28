class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                el = nums[i];
                cnt++;
            }
            else if (nums[i] == el) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        int cnt1 = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == el) cnt1++;
        }

        if (cnt1 > (n / 2)) {
            return el;
        }
        return -1;
    }
};
