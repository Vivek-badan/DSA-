class Solution {
public:
    int numberOfSpecialChars(string word) {

        // Store last occurrence of lowercase
        vector<int> lastLower(26, -1);

        // Store first occurrence of uppercase
        vector<int> firstUpper(26, -1);

        // Traverse the string
        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            // Lowercase
            if(ch >= 'a' && ch <= 'z') {

                lastLower[ch - 'a'] = i;
            }

            // Uppercase
            else {

                if(firstUpper[ch - 'A'] == -1) {

                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        // Check condition
        for(int i = 0; i < 26; i++) {

            // Both lowercase and uppercase exist
            // and lowercase comes before uppercase
            if(lastLower[i] != -1 &&
               firstUpper[i] != -1 &&
               lastLower[i] < firstUpper[i]) {

                count++;
            }
        }

        return count;
    }
};