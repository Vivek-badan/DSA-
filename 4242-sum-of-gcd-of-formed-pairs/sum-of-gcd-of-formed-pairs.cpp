class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {

        typedef long long ll;

        int n = nums.size();

        vector<ll> mx(n, 0);
        vector<ll> PrefixGcd(n, 0);

        // Step-1: Finding the mx[i]
        for (int i = 0; i < n; i++) {

            if (i == 0) {
                mx[i] = nums[i];
            }
            else {
                mx[i] = max((ll)nums[i], mx[i - 1]);
            }
        }

        // Step-2: Finding the Prefix GCD
        for (int i = 0; i < n; i++) {

            if (nums[i] == mx[i]) {
                PrefixGcd[i] = nums[i];
            }
            else {
                PrefixGcd[i] = gcd(nums[i], mx[i]);
            }
        }

        // Step-3: Sort the PrefixGcd
        sort(PrefixGcd.begin(), PrefixGcd.end());

        // Step-4: Compute the pairs
        int l = 0;
        int r = PrefixGcd.size() - 1;

        ll sumofpair = 0;

        while (l < r) {

            ll sum = gcd(PrefixGcd[l], PrefixGcd[r]);

            sumofpair += sum;

            l++;
            r--;
        }

        return sumofpair;
    }
};