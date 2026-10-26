class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int nums:st){
            if(nums==INT_MIN || st.find(nums-1)==st.end()){
                int current = nums;
                int count = 1;
                while(current!=INT_MAX && st.find(current+1)!=st.end()){
                    current++;
                    count++;
                }
                 longest=max(longest,count);

                
            }
           
        }

        return longest;
    }
};