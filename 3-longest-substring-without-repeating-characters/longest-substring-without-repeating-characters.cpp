class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> hash(256, -1); 
    int l=0,r=0,maxlen=0;
    int n= s.size();
    if (s.size() == 0) return 0;
    while(r<n){
        int len=0;
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }

        }
        hash[s[r]]=r;
        len  =r-l+1;
        maxlen=max(maxlen,len);
        r++;
    }
     return maxlen;
    }
};
