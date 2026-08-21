class Solution {
public:

    long long countValid(long long X, vector<int>& coins) {

        int n = coins.size();

        long long count = 0;

        for(int mask = 1; mask < (1 << n); mask++) {

            long long l = 1;
            int bits = 0;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {

                    l = lcm(l, (long long)coins[i]);

                    bits++;
                }
            }

            if(bits % 2 == 1)
                count += X / l;
            else
                count -= X / l;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1e18;

        while(low < high) {

            long long mid = low + (high - low) / 2;

            if(countValid(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};