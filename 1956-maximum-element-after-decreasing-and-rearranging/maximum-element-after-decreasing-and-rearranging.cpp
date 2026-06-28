class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: First element must always be 1
        arr[0] = 1;

        // Step 3: Process the remaining elements
        for (int i = 1; i < arr.size(); i++) {

            // Current element cannot be greater than previous + 1
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        // Step 4: The last element is the maximum
        return arr.back();
    }
};