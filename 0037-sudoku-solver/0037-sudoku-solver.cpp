class Solution {
    bool isSafe(int row, int col, char val, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[row][i]==val) return false;

            if(board[i][col]==val) return false;

            if(board[3*(row/3) + i/3] [3*(col/3) + i%3]==val) return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char val='1'; val<='9'; val++){
                        if(isSafe(i, j ,val ,board )){
                            board[i][j]=val;
                            bool rest=helper(board);
                            if(rest){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};