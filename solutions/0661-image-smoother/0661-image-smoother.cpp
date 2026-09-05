class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> answer (img.size(), vector<int> (img[0].size()));

        for(int i = 0; i < img.size(); i++){
            for(int j = 0; j < img[i].size(); j++){
               /* int ans = 0;
               int count = 0;
               for(int r = i - 1; r <= i + 1; r++){
                   for(int c = j - 1; c <= j + 1; c++){
                       if(r < img.size() && c < img[i].size() && i > -1 && j > -1){
                           ans += img[r][c];
                           count++;
                       }
                   }
               }  */

                int ans = img[i][j];
                int count = 1;
                if(i - 1 >= 0){
                    ans += img[i - 1][j];
                    count++;
                }
                if(j - 1 >= 0){
                    ans += img[i][j - 1];
                    count++;
                }
                if(i - 1 >= 0 && j - 1 >= 0){
                    ans += img[i - 1][j - 1];
                    count++;
                }
                if(i - 1 >= 0 && j + 1 < img[i].size()){
                    ans += img[i - 1][j + 1];
                    count++;
                }
                if(j + 1 < img[i].size()){
                    ans += img[i][j + 1];
                    count++;
                }
                if(i + 1 < img.size()){
                    ans += img[i + 1][j];
                    count++;
                }
                if(i + 1 < img.size() && j - 1 >= 0){
                    ans += img[i + 1][j - 1];
                    count++;
                }
                if(i + 1 < img.size() && j + 1 < img[i].size()){
                    ans += img[i + 1][j + 1];
                    count++;
                }
                answer[i][j] = ans / count;
                answer[i][j] = ans / count;
            }
        }
        return answer;
    }
};

