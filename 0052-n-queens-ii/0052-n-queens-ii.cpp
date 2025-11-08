class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n) {
        // Check vertical up
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void helper(int row, vector<vector<string>> &ans, int n, vector<string> &board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(row + 1, ans, n, board);
                board[row][col] = '.'; // backtrack
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        helper(0, ans, n, board);
        return ans.size();
    }
};