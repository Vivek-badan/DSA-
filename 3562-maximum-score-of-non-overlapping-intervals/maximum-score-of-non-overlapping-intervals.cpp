class Solution {
public:
    struct State {
        long long weight;
        vector<int> indices;
    };

    vector<array<long long, 4>> arr;
    vector<vector<State>> memo;
    vector<vector<bool>> vis;

    State better(State a, State b) {
        if (a.weight != b.weight) {
            return (a.weight > b.weight) ? a : b;
        }

        if (a.indices < b.indices) {
            return a;
        }

        return b;
    }

    State solve(int i, int k) {
        int n = arr.size();

        if (i == n || k == 0) {
            return {0, {}};
        }

        if (vis[i][k]) {
            return memo[i][k];
        }

        vis[i][k] = true;

        // Option 1: skip current interval
        State skip = solve(i + 1, k);

        // Option 2: take current interval
        long long rightEnd = arr[i][1];
        long long weight = arr[i][2];
        int originalIndex = arr[i][3];

        // Find first interval whose start > current right end
        int low = i + 1;
        int high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid][0] > rightEnd) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        int nextIndex = low;

        State take = solve(nextIndex, k - 1);

        take.weight += weight;
        take.indices.push_back(originalIndex);

        // Required because answer must contain indices
        // in lexicographically smallest order
        sort(take.indices.begin(), take.indices.end());

        memo[i][k] = better(skip, take);

        return memo[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort according to starting point
        sort(arr.begin(), arr.end());

        memo.resize(n, vector<State>(5));
        vis.resize(n, vector<bool>(5, false));

        return solve(0, 4).indices;
    }
};