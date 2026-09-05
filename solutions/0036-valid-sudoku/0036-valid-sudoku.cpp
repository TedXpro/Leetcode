class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> rows[9];
        set<char> columns[9];
        set<char> boxes[9];

        for(int i = 0; i <= 8; i++){
            for(int j = 0; j <= 8; j++){
                char ch = board[i][j];
                if(ch == '.')
                    continue;
                
                int boxIndex = (i / 3) * 3 + j / 3;
                if((rows[i].find(ch) != rows[i].end()) || (columns[j].find(ch) != columns[j].end()) || (boxes[boxIndex].find(ch) != boxes[boxIndex].end()))
                    return false;
                // else if()
                //     return false;
                // else if
                //     return false;
                rows[i].insert(ch);
                columns[j].insert(ch);
                boxes[boxIndex].insert(ch);
            }
        }
        return true;
    }
};