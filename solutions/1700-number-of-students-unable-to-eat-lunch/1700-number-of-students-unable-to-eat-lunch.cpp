class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> line;
        int ones = 0, zeros = 0;
        for(int num : students){
            line.push(num);
            num == 1 ? ones++ : zeros++;
        }

        bool possible = true;
        int index = 0;
        int count = 0;
        while(possible && !line.empty()){
            int num = line.front();
            if(num == sandwiches[index]){
                index++;
                line.pop();
                num == 1 ? ones-- : zeros--;
            } else {
                if(sandwiches[index] == 1 && ones == 0){
                    possible = false;
                    count = zeros;
                } else if(sandwiches[index] == 0 && zeros == 0){
                    possible = false;
                    count = ones;
                } else{
                    line.pop();
                    line.push(num);
                }

            }
        }

        return count;
    }
};