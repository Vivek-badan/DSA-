class Solution {
public:
    string smallestPalindrome(string s) {

        if(s.size()==1) return s;

        // STEP-1
        map<char,int> mpp;

        for(char ch : s)
            mpp[ch]++;

        // STEP-2
        string first_string="";
        string middle_string="";

        for(char c='a'; c<='z'; c++){

            if(mpp.find(c)!=mpp.end()){

                for(int i=0;i<mpp[c]/2;i++)
                    first_string += c;

                if(mpp[c]%2==1)
                    middle_string += c;
            }
        }

        // STEP-3
        string second = first_string;

        reverse(second.begin(), second.end());

        return first_string + middle_string + second;
    }
};