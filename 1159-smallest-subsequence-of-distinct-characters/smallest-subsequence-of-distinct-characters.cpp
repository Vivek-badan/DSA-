class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        // Count frequency
        for(char ch : s)
            freq[ch - 'a']++;

        string st;

        for(char ch : s) {

            freq[ch - 'a']--;

            // Already taken
            if(vis[ch - 'a'])
                continue;

            // Maintain increasing lexicographical order
            while(!st.empty() &&
                  st.back() > ch &&
                  freq[st.back() - 'a'] > 0) {

                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            vis[ch - 'a'] = true;
        }

        return st;
    }
};