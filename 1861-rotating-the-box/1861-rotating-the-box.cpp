class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size(), cols = box[0].size();

        for(int r = rows - 1; r >= 0; r--){
            for(int i = cols - 1, c = cols - 1; c >= 0; c--){
                if(box[r][c] == '#'){
                    char temp = box[r][i];
                    box[r][i] = box[r][c];
                    box[r][c] = temp;
                    i--;
                } else if(box[r][c] == '*'){
                    i = c - 1;
                }
            }
        }

        vector<vector<char>> answer;
        for(int c = 0; c < cols; c++){
            vector<char> curr;
            for(int r = rows - 1; r >= 0; r--){
                curr.push_back(box[r][c]);
            }
            answer.push_back(curr);
        }

        return answer;

    }
};