class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0){
            vector<int> answer (code.size(), 0);
            return answer;
        } else if(k > 0){
            int currSum = 0;
            int count = 0;
            int index = 1;
            while(count != k){
                if(index == code.size()){
                    index = 0;                    
                }
                currSum += code[index];
                count++;
                index++;
            }
            vector<int> answer;
            answer.push_back(currSum);
            int left = 1, right = index;
            index = 1;
            while(index < code.size()){
                if(right == code.size()){
                    right = 0;
                } 
                currSum -= code[left];
                left++;
                if(left == code.size()){
                    left = 0;
                }
                currSum += code[right];
                answer.push_back(currSum);
                right++;

                index++;
            }
            return answer;
        }

        // k < 0

        int currSum = 0;
        int count = 0;
        int index = code.size() - 1;
        while(count != abs(k)){
            if(index == -1){
                index = code.size() - 1;                    
            }
            currSum += code[index];
            count++;
            index--;
        }
        vector<int> answer;
        answer.push_back(currSum);
        int left = index + 1, right = 0;
        index = 1;
        while(index < code.size()){
            if(right == code.size()){
                right = 0;
            } 
            if(left == code.size()){
                left = 0;
            }
            currSum -= code[left];
            left++;
            
            currSum += code[right];
            answer.push_back(currSum);
            right++;

            index++;
        }
        return answer;
    }
};