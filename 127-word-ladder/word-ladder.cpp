// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         //Step-1 initialization
//         queue<pair<string,int>>q;
//         q.push({beginWord,1});
//         unordered_set<int>st(wordList.begin(),wordList.end());
//         st.erase(beginWord);

//         //STEP-2 queue checking

//         while(!q.empty()){
//             string word=q.front().first;
//             int steps=q.front().second;
//             q.pop();
//             if(word==target){
//                 return steps;
//             }

//             for(int i=0;i<word.size();i++){
//                 char original=word[i];
//                 for(char ch='a';ch<=z;ch++){
//                     word[i]=ch;
//                     if(st.find(word)!=st.end()){
//                         st.erase(word);
//                         q.push_back({word,steps+1});
//                     }

//                 }
//                 word[i]=original;
//             }
//         }
//         return 0;
        
//     }
// };'
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Step-1: Initialization
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        // ❌ unordered_set<int>
        // ✔️ It should store strings, not integers.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Remove the beginWord if present
        st.erase(beginWord);

        // Step-2: BFS
        while(!q.empty()){

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // ❌ target doesn't exist
            // ✔️ Use endWord
            if(word == endWord){
                return steps;
            }

            // Try changing every character
            for(int i = 0; i < word.size(); i++){

                char original = word[i];

                // ❌ z is not defined
                // ✔️ Character should be 'z'
                for(char ch = 'a'; ch <= 'z'; ch++){

                    word[i] = ch;

                    if(st.find(word) != st.end()){

                        st.erase(word);

                        // ❌ queue has push(), not push_back()
                        q.push({word, steps + 1});
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};