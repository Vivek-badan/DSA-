
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // Initially, every child gets one candy.
        vector<int> ans(n, 1);

        // First pass: left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            }
        }

        // Second pass: right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }

        // Calculate total candies
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += ans[i];
        }

        return sum;
    }
};

//conditions are :-
// 1. each std gets 1 candy atleast
// 2.higher rating children gets more candies thann neighbours.
//return ->minimum number of candies so that every one gets it .