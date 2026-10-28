
class Solution {
public:
    int expand(string& s, int left, int right) {

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {

            // Find odd-length palindrome
            int len1 = expand(s, i, i);

            // Find even-length palindrome
            int len2 = expand(s, i, i + 1);

            // Choose longer palindrome
            int len = max(len1, len2);

            if (len > maxLen) {

                maxLen = len;

                // TODO: Calculate starting index
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
