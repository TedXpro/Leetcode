class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<string> memo;
        for(vector<int> obs : obstacles){
            memo.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int x = 0, y = 0;
        int currDir = 0;
        int answer = 0;
        for(int command : commands){
            if(command == -1){
                currDir++;
                if(currDir == 4)
                    currDir = 0;
            }
            else if(command == -2){
                currDir--;
                if(currDir == -1)
                    currDir = 3;
            }
            else{
                while(command-- > 0 && memo.find(to_string(x + directions[currDir][0]) +
                 "," + to_string(y + directions[currDir][1])) == memo.end()){
                    x += directions[currDir][0];
                    y += directions[currDir][1];
                }
            }
            answer = max(answer, x * x + y * y);
        }
        return answer;
        
    }
};