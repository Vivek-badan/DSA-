class Solution {
public:
    long long ncr(int n, int r, int k) {
        r = min(r, n - r);
        long long result = 1;

        for (int i = 0; i < r; i++) {
            result = result * (n - r + i + 1) / (i + 1);
            if (result >= k) return k;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        char mid = ' ';

        if (n % 2 == 1)
            mid = s[n / 2];

        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2)
                continue;
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
            count[i] /= 2;

        string halfResult = "";
        int half = n / 2;

        for (int pos = 0; pos < half; pos++) {
            bool placed = false;

            for (int j = 0; j < 26; j++) {
                if (count[j] == 0)
                    continue;

                count[j]--;

                int letters = 0;
                for (int c = 0; c < 26; c++)
                    letters += count[c];

                long long ways = 1;

                for (int c = 0; c < 26; c++) {
                    if (count[c] > 0) {
                        ways *= ncr(letters, count[c], k);
                        letters -= count[c];
                    }
                    if (ways >= k)
                        break;
                }

                if (ways >= k) {
                    halfResult.push_back(char('a' + j));
                    placed = true;
                    break;
                }

                k -= ways;
                count[j]++;
            }

            if (!placed)
                return "";
        }

        string rev = halfResult;
        reverse(rev.begin(), rev.end());

        if (mid != ' ')
            return halfResult + mid + rev;
        else
            return halfResult + rev;
    }
};