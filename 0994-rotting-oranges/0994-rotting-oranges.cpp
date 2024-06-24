#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int r, c;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<int, int>> q;
        int time = 0;

        // Push all initially rotten oranges into the queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }

        // BFS traversal
        while (!q.empty()) {
            int rotten_oranges = q.size();
            bool hasRotten = false;

            while (rotten_oranges--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if (valid(ni, nj) && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push(make_pair(ni, nj));
                        hasRotten = true;
                    }
                }
            }

            if (hasRotten) {
                time++;
            }
        }

        // Check if any fresh orange is left
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
