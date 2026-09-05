class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.size());
        int count = 0, operations = 0;
        for(int i = 0; i < boxes.size(); i++){
            answer[i] += operations;
            count += boxes[i] - '0';
            operations += count;
        }

        count = 0, operations = 0;
        for(int i = boxes.size() - 1; i >= 0; i--){
            answer[i] += operations;
            count += boxes[i] - '0';
            operations += count;
        }
        return answer;
    }
};