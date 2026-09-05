class Solution {
private:
    vector<vector<char>> board;
    vector<vector<bool>> memo;
    string word;

    bool DFS(int row, int col, int index) {
        if (index >= word.length())
            return true;
        if (row >= memo.size() || row < 0 || col >= memo[row].size() || col < 0 || memo[row][col])
            return false;
        if (board[row][col] == word[index]) {
            memo[row][col] = true;
            bool isFound = DFS(row - 1, col, index + 1) || DFS(row + 1, col, index + 1) ||
                           DFS(row, col + 1, index + 1) || DFS(row, col - 1, index + 1);
            memo[row][col] = false;
            return isFound;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty())
            return false;

        this->board = board;
        this->word = word;
        memo.resize(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (DFS(i, j, 0))
                    return true;
            }
        }

        return false;
    }
};