// class Solution {
//     unordered_map<string, bool> memo;
//     vector<vector<char>> bo;
//     string wo;

//     bool dfs(int index, int row, int col){
//         if(index >= wo.length())
//             return true;
//         string key = to_string(row) + "," + to_string(col);
//         if(row >= bo.size() || row < 0 || col >= bo[0].size() || col < 0)
//             return false;
        
//         if(memo.find(key) != memo.end() && memo[key] == true)
//             return false;

//         if(bo[row][col] == wo[index]){
//             memo[key] = true;
//             bool found = dfs(index + 1, row - 1, col) || 
//             dfs(index + 1, row + 1, col) ||
//             dfs(index + 1, row, col + 1) ||
//             dfs(index + 1, row, col - 1);
//             memo[key] = false;
//             return found;
//         }

//         return false;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         this->bo = board;
//         this->wo = word;
//         for(int row = 0; row < bo.size(); row++){
//             for(int col = 0; col < bo[0].size(); col++){
//                 if(dfs(0, row, col))
//                     return true;
//             }
//         }

//         return false;
//     }
    
// };

class Solution {
private:
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    string word;

    bool DFS(int row, int col, int index) {
        if (index >= word.length())
            return true;
        if (row >= visited.size() || row < 0 || col >= visited[row].size() || col < 0 || visited[row][col])
            return false;
        if (board[row][col] == word[index]) {
            visited[row][col] = true;
            bool isFound = DFS(row - 1, col, index + 1) || DFS(row + 1, col, index + 1) ||
                           DFS(row, col + 1, index + 1) || DFS(row, col - 1, index + 1);
            visited[row][col] = false;
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
        visited.resize(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (DFS(i, j, 0))
                    return true;
            }
        }

        return false;
    }
};