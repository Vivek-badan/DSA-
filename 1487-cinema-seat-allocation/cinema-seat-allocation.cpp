class Solution {
public:

    bool canPlace(vector<int>& seats, int l, int r) {
        for(int seat : seats) {
            if(seat >= l && seat <= r) {
                return false;
            }
        }

        return true;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Step 1 + Step 2:
        // Store reserved seats row-wise
        unordered_map<int, vector<int>> vis;

        for(auto seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            vis[row].push_back(col);
        }

        // Rows having no reserved seats
        int count = (n - vis.size()) * 2;

        // Step 3:
        // Process only rows having reserved seats
        for(auto it : vis) {

            int row = it.first;
            vector<int> seats = it.second;

            bool left = canPlace(seats, 2, 5);
            bool middle = canPlace(seats, 4, 7);
            bool right = canPlace(seats, 6, 9);

            // Left and right don't overlap,
            // so both families can be placed.
            if(left && right) {
                count += 2;
            }
            // Otherwise, if any one block works,
            // we can place one family.
            else if(left || middle || right) {
                count += 1;
            }
        }

        return count;
    }
};