class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals),end(intervals),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int count=0;
        int prevend=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=prevend){
                prevend=intervals[i][1];
            }
            else{
                count++;
            }
        }
        return count;
    }
};