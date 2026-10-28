
class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();
        int sign = 1;
        long long ans = 0;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check positive or negative sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Step 3: Convert characters into digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // Step 4: Handle integer overflow
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(ans * sign);
    }
};
