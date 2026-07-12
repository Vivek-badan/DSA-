class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();

        // Step-1: Copy the original array and sort it
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        // Step-2: Store <number, rank> in the hashmap
        unordered_map<int, int> mpp;

        int rank = 1;

        for (int i = 0; i < n; i++) {

            // Assign rank only if the number is seen for the first time
            if (mpp.find(temp[i]) == mpp.end()) {
                mpp[temp[i]] = rank;
                rank++;
            }
        }

        // Step-3: Traverse the original array
        // and replace every number with its rank
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = mpp[arr[i]];
        }

        return ans;
    }
};