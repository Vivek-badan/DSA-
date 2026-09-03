class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minel =*min_element(begin(nums1),end(nums1));
        if(minel%2==1) return true;
        for(int &nums : nums1){
            if(nums%2==1) return false;
        }
        return true;
    }
};