class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // Step 1: Store knowledge in map
        unordered_map<string, string> mp;

        for (auto &it : knowledge) {
            mp[it[0]] = it[1];
        }


        string result = "";

        // Step 2: Traverse string
        for (int i = 0; i < s.size(); i++) {

            // Normal character
            if (s[i] != '(') {
                result += s[i];
            }

            // Found '('
            else {

                i++;  // move after '('

                string query = "";

                // Build key until ')'
                while (i < s.size() && s[i] != ')') {
                    query += s[i];
                    i++;
                }


                // Step 3: Search key in map
                if (mp.find(query) != mp.end()) {

                    result += mp[query];
                }
                else {

                    result += "?";
                }
            }
        }

        return result;
    }
};