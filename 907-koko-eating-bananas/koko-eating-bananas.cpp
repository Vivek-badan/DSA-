class Solution {
public:
    int maxelement(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int x : piles) {
            maxi = max(maxi, x);
        }
        return maxi;
    }

    long long calculatehrs(vector<int>& piles, int hourly) {
        if (hourly == 0) return LLONG_MAX;  // guard condition
        long long totalh = 0;  // ✅ use long long
        for (int x : piles) {
            totalh += ceil((double)x / (double)hourly);
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxelement(piles);
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalhrs = calculatehrs(piles, mid);  // ✅ long long safe

            if (totalhrs <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
