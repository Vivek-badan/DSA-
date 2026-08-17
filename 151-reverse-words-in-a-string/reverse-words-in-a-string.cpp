class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();

        reverse(s.begin(), s.end());

        string word = "";
        string ans = "";

        for(int i = 0; i < n; i++) {

            // Skip spaces
            if(s[i] == ' ')
                continue;

            // Extract word
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse the word
            reverse(word.begin(), word.end());

            // Add to answer
            if(!ans.empty())
                ans += " ";

            ans += word;

            // Clear for next word
            word.clear();
        }

        return ans;
    }
};