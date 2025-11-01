class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int last= n -1;
        
        vector<int>ans(2,-1);

        //First occurence

        while(start<=last){
            int mid = start+(last-start)/2 ;
            if(target==nums[mid]){
                
                ans[0]=mid;
                last=mid-1;
                
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                last=mid-1;
            }
        }
        //second occurence 
    start = 0;
    last = n - 1;   
    
        while(start<=last){
            int mid = start+(last-start)/2 ;
            if(target==nums[mid]){
                
                ans[1]=mid;
               
                start=mid+1;            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                last=mid-1;
            }
        }
        
        return ans;
        
    }
};