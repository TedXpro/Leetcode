class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stackOperations;
        int index = 0;
        for(int i = 1; i <= n; i++){
            if(target[index] == i){
                stackOperations.push_back("Push");
                index++;
                if(index == target.size())
                    break;
            }
            else{
                stackOperations.push_back("Push");
                stackOperations.push_back("Pop");
            }
        }        
        return stackOperations;
    }
};