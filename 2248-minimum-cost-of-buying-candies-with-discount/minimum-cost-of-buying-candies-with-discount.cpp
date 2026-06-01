class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end());

        int sum = 0;

        for(int i = cost.size() - 1; i >= 0; i -= 3) {

            sum += cost[i];   // largest candy

            if(i - 1 >= 0)
                sum += cost[i - 1];  // second largest candy

            // i-2 is free, so do nothing
        }

        return sum;
    }
};