class Solution {
public:
    int numberOfSpecialChars(string word) {

        int count = 0;

        // To avoid duplicate counting
        vector<int> visited(26, 0);

        for(int i = 0; i < word.size(); i++) {

            for(int j = 0; j < word.size(); j++) {

                // Check lowercase-uppercase pair
                if(tolower(word[i]) == tolower(word[j]) &&
                   word[i] != word[j]) {

                    int idx = tolower(word[i]) - 'a';

                    // Count only once
                    if(visited[idx] == 0) {
                        count++;
                        visited[idx] = 1;
                    }
                }
            }
        }

        return count;
    }
};