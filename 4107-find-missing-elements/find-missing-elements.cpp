class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        //step-1
        sort(nums.begin(),nums.end());
        int smallest=nums[0];
        int largest=nums[n-1];

        //step-2
        for(int i = 0; i < n - 1; i++) {
    int curr = nums[i];

    while(curr + 1 < nums[i + 1]) {
        ans.push_back(curr + 1);
        curr++;
    }
}
        return ans;        
        
    }
};