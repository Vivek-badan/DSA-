class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freqText(26, 0);
        vector<int> freqTarget(26, 0);

        for(char ch : s) {
            freqText[ch - 'a']++;
        }

        for(char ch : target) {
            freqTarget[ch - 'a']++;
        }

        int ans = INT_MAX;

        for(int i = 0; i < 26; i++) {

            if(freqTarget[i] > 0) {

                ans = min(ans,
                          freqText[i] / freqTarget[i]);
            }
        }

        return ans;
    }
};