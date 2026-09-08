class Solution {
public:
    int countCommas(int n) {

        // 1 -> 999
        if (n <= 999) {
            return 0;
        }

        // 1000 -> 9999
        if (1000 <= n && n <= 9999) {
            return n - 999;
        }

        // 10000 -> 99999
        if (10000 <= n && n <= 99999) {
            // 1000 -> 9999
            int firstRange = 9999 - 1000 + 1;

            // 10000 -> n
            int secondRange = n - 10000 + 1;

            return firstRange + secondRange;
        }

        // n == 100000
        if (n == 100000) {
            int firstRange = 9999 - 1000 + 1;
            int secondRange = 99999 - 10000 + 1;
            int thirdRange = 1; // 100,000

            return firstRange + secondRange + thirdRange;
        }

        return 0;
    }
};