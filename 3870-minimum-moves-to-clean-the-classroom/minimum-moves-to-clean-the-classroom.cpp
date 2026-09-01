class Solution {
public:

    struct State {
        int r;
        int c;
        int energy;
        int mask;
        int moves;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // STEP 1:
        // Find starting position and give every litter an ID.

        int sr = 0, sc = 0;
        int litterCount = 0;

        vector<vector<int>> litterId(
            m,
            vector<int>(n, -1)
        );

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }


        // If there is no litter, we're already done.

        if (litterCount == 0)
            return 0;


        // STEP 2:
        // Mask when every litter has been collected.

        int finalMask = (1 << litterCount) - 1;


        // STEP 3:
        // BFS queue.

        queue<State> q;

        q.push({
            sr,
            sc,
            energy,
            0,
            0
        });


        // STEP 4:
        // visited[row][column][remainingEnergy][litterMask]

        vector visited(
            m,
            vector(
                n,
                vector(
                    energy + 1,
                    vector<bool>(
                        1 << litterCount,
                        false
                    )
                )
            )
        );

        visited[sr][sc][energy][0] = true;


        // STEP 5:
        // Four directions.

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};


        // STEP 6:
        // BFS.

        while (!q.empty()) {

            State curr = q.front();
            q.pop();


            // Try all 4 directions.

            for (int d = 0; d < 4; d++) {

                int nr = curr.r + dr[d];
                int nc = curr.c + dc[d];


                // Outside grid.

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }


                // Obstacle.

                if (classroom[nr][nc] == 'X') {
                    continue;
                }


                // No energy means we cannot move.

                if (curr.energy == 0) {
                    continue;
                }


                // Moving costs 1 energy.

                int newEnergy = curr.energy - 1;


                // Recharge station.

                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }


                // Initially keep same collected litter.

                int newMask = curr.mask;


                // If this cell contains litter,
                // mark it as collected.

                if (classroom[nr][nc] == 'L') {

                    int id = litterId[nr][nc];

                    newMask =
                        newMask | (1 << id);
                }


                // All litter collected.

                if (newMask == finalMask) {
                    return curr.moves + 1;
                }


                // Already explored this exact state.

                if (visited[nr][nc][newEnergy][newMask]) {
                    continue;
                }


                // Mark visited.

                visited[nr][nc][newEnergy][newMask] = true;


                // Add to BFS.

                q.push({
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    curr.moves + 1
                });
            }
        }


        // Impossible to collect all litter.

        return -1;
    }
};