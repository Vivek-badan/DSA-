class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt[3] = {0};

        for(int x : stones) {
            cnt[x % 3]++;
        }

        // If Alice takes a remainder-0 stone,
        // it doesn't change the modulo state.
        if(cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // Odd number of remainder-0 stones
        return abs(cnt[1] - cnt[2]) > 2;
    }
};