class Solution {
public:
    int maximumLength(vector<int>& nums) {

        using ll = long long;

        map<ll, int> freqMap;

        for (auto el : nums)
            freqMap[el]++;

        int ans = 1;

        for (auto [el, freq] : freqMap) {

            ll x = el;
            int count = 0;

            while (freqMap.find(x) != freqMap.end() && freqMap[x]) {

                if (x == 1)
                    count += freqMap[1];

                else if (freqMap[x] >= 2)
                    count += 2;

                else if (freqMap[x] == 1) {
                    count += 1;
                    break;
                }

                freqMap[x] = 0;

                if (x > 1000000)
                    break;

                x = x * x;
            }

            ans = max(ans, count - (count % 2 == 0));
        }

        return ans;
    }
};