class Solution {
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r < 0 || r == board.size() || c < 0 || c == board[0].size() || board[r][c] != 'O'){
            return;
        }

        board[r][c] = 'Y';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O' && (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)){
                    dfs(board, i, j);
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};