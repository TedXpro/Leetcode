class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        unordered_map<int, int> oldMemo;
        oldMemo[0] = 0;
        oldMemo[1] = 1;
        oldMemo[2] = 0;
        oldMemo[3] = 1;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 0){
                    int count = 0;
                    for(int r = i - 1; r < i + 2; r++){
                        for(int c = j - 1; c < j + 2; c++){
                            if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size()){
                                if(oldMemo[board[r][c]]){
                                    count++;
                                }
                            }
                        }
                    }
                    if(count == 3){
                        board[i][j] = 2;
                    }
                } else {
                    int count = -1;
                    for(int r = i - 1; r < i + 2; r++){
                        for(int c = j - 1; c < j + 2; c++){
                            if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size()){
                                if(oldMemo[board[r][c]]){
                                    count++;
                                }
                            }
                        }
                    }

                    if(count < 2){
                        board[i][j] = 1;
                    } else if(count == 2 || count == 3){
                        board[i][j] = 3;
                    } else if(count > 3){
                        board[i][j] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 1){
                    board[i][j] = 0;
                } else if(board[i][j] == 2){
                    board[i][j] = 1;
                } else if(board[i][j] == 3){
                    board[i][j] = 1;
                }
            }
        }
    }
};