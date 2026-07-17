class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int n = nums.size();

        // Step-1 : Find the maximum element
        int maxi = *max_element(nums.begin(), nums.end());

        // Step-2 : Store frequency of every number
        vector<int> freq(maxi + 1, 0);

        for (int x : nums)
            freq[x]++;

        // Step-3 : cnt[d] = numbers divisible by d
        vector<long long> cnt(maxi + 1, 0);

        for (int d = 1; d <= maxi; d++) {

            for (int multiple = d; multiple <= maxi; multiple += d) {

                cnt[d] += freq[multiple];
            }
        }

        // Step-4 : exactPairs[d] = pairs whose gcd is exactly d
        vector<long long> exactPairs(maxi + 1, 0);

        for (int d = maxi; d >= 1; d--) {

            long long total = cnt[d] * (cnt[d] - 1) / 2;

            for (int multiple = 2 * d; multiple <= maxi; multiple += d) {

                total -= exactPairs[multiple];
            }

            exactPairs[d] = total;
        }

        // Step-5 : Prefix array over gcd values
        vector<long long> prefix(maxi + 1, 0);

        for (int d = 1; d <= maxi; d++) {

            prefix[d] = prefix[d - 1] + exactPairs[d];
        }

        // Step-6 : Answer Queries using Binary Search
        vector<int> ans;

        for (long long q : queries) {

            int gcdValue = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};