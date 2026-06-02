#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        long long ans = LLONG_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {

                // Land -> Water
                long long landFinish =
                    (long long)landStartTime[i] + landDuration[i];

                long long finish1 =
                    max(landFinish, (long long)waterStartTime[j])
                    + waterDuration[j];

                ans = min(ans, finish1);

                // Water -> Land
                long long waterFinish =
                    (long long)waterStartTime[j] + waterDuration[j];

                long long finish2 =
                    max(waterFinish, (long long)landStartTime[i])
                    + landDuration[i];

                ans = min(ans, finish2);
            }
        }

        return (int)ans;
    }
};