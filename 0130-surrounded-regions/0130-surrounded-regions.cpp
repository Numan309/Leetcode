class Solution {
public:
    int r;
    int c;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();

        // Apply BFS operation on the border where 'O' is present, replace 'O' with 'T'
        queue<pair<int, int>> q;

        // First row
        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O') {
                q.push(make_pair(0, j));
                board[0][j] = 'T';
            }
        }

        // First column
        for (int i = 1; i < r; i++) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
                board[i][0] = 'T';
            }
        }

        // Last row
        for (int j = 1; j < c; j++) {
            if (board[r - 1][j] == 'O') {
                q.push(make_pair(r - 1, j));
                board[r - 1][j] = 'T';
            }
        }

        // Last column
        for (int i = 1; i < r - 1; i++) {
            if (board[i][c - 1] == 'O') {
                q.push(make_pair(i, c - 1));
                board[i][c - 1] = 'T';
            }
        }

        // BFS to mark all connected 'O's from border
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];
                if (valid(ni, nj) && board[ni][nj] == 'O') {
                    board[ni][nj] = 'T';
                    q.push(make_pair(ni, nj));
                }
            }
        }

        // Replace all 'O' with 'X' and all 'T' back to 'O'
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
