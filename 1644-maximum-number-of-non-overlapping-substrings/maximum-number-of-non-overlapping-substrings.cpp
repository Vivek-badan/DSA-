class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Step 1: Find first and last occurrence
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            first[ch] = min(first[ch], i);
            last[ch] = i;
        }

        vector<pair<int, int>> intervals;

        // Step 2: Try to create a valid interval
        // starting from the first occurrence of each character
        for (int c = 0; c < 26; c++) {

            if (first[c] == n)
                continue;

            int start = first[c];
            int end = last[c];

            bool valid = true;

            // Expand interval if required
            for (int i = start; i <= end; i++) {

                int ch = s[i] - 'a';

                // This character started before our interval,
                // so this interval can never be valid.
                if (first[ch] < start) {
                    valid = false;
                    break;
                }

                // If this character occurs later,
                // expand our interval.
                end = max(end, last[ch]);
            }

            if (valid) {
                intervals.push_back({start, end});
            }
        }

        // Step 3: Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        // Step 4: Greedily take non-overlapping intervals
        vector<string> ans;

        int previousEnd = -1;

        for (auto [start, end] : intervals) {

            if (start > previousEnd) {

                ans.push_back(
                    s.substr(start, end - start + 1)
                );

                previousEnd = end;
            }
        }

        return ans;
    }
};