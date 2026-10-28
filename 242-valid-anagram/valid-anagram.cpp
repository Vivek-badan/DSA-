class Solution {
public:
    bool isAnagram(string s, string t) {
        //base case 
        if(s.size()!=t.size()) return false;
        vector<int>freq(26,0);

        for(char ch:s){
            freq[ch-'a']++;
        }

        for(char sh:t){
            freq[sh-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;

    }
};