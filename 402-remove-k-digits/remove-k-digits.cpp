class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // remove remaining k digits from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        // remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        if (res.empty()) return "0";
        return res;
    }
};
