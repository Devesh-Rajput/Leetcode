class Solution {
    void helper(int i, int j, int& ans, vector<vector<int>>& mat, int& m, int& n,
                vector<vector<int>>& direction) {

        // check entire row
        for(int col = 0; col < n; col++){
            if(col != j && mat[i][col] == 1)
                return;
        }

        // check entire column
        for(int row = 0; row < m; row++){
            if(row != i && mat[row][j] == 1)
                return;
        }

        ans++;
    }

public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    helper(i, j, ans, mat, m, n, direction);
                }
            }
        }

        return ans;
    }
};