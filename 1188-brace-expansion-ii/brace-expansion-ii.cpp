class Solution {
public:
    int n;
    string s;
    int idx = 0;


    set<string> getunit() {

        set<string> result;

        if (s[idx] == '{') {

            idx++; // skip '{'

            result = performunion();

            idx++; // FIX 1: skip the closing '}'
        }
        else {

            result = {string(1, s[idx])};

            idx++; // FIX 2: move to next character
        }

        return result;
    }


    set<string> performconcat() {

        // FIX 3:
        // It should be empty string "", NOT space " "
        // "" is identity for concatenation
        set<string> result = {""};


        // FIX 4:
        // Parentheses are necessary.
        // Otherwise isalpha(s[idx]) may execute even when idx == n
        while (idx < n &&
               (s[idx] == '{' || isalpha(s[idx]))) {

            set<string> temp = getunit();

            set<string> concatresult;


            // Cartesian Product
            for (const string& left : result) {

                for (const string& right : temp) {

                    concatresult.insert(left + right);
                }
            }

            result = concatresult;
        }

        return result;
    }


    set<string> performunion() {

        set<string> result;

        while (true) {

            set<string> temp = performconcat();

            // Union
            result.insert(temp.begin(), temp.end());


            if (idx < n && s[idx] == ',') {

                idx++; // skip comma
            }
            else {

                break;
            }
        }

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        n = expression.length();
        s = expression;
        idx = 0;

        set<string> st = performunion();

        vector<string> result(st.begin(), st.end());

        return result;
    }
};