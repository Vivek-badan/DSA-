#include <algorithm>
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        long long max_el= LONG_MIN; 
        long long min_el= LONG_MAX;
        long long ans=0;

        for(int x : nums){
            max_el= max((long long)x,max_el);
            min_el=min((long long)x,min_el);
            ans= max_el-min_el;
        }

        return k*ans;
        
    }
};