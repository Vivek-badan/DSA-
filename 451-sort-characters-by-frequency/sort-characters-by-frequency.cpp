class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>mpp;
        for(auto x:s){
            mpp[x]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            pair<int,char>p=pq.top();
            pq.pop();
            for(int i=0;i<p.first;i++){
                ans += p.second;
            }
        }
        return ans;
    }
};