class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> memo(folder.begin(), folder.end());
        vector<string> answer;
        
        for(string& currFolder : folder){
            string curr = currFolder;
            bool found = false;
            while(!curr.empty()){
                auto pos = curr.find_last_of('/');
                
                if(pos == string::npos){
                    break;
                }

                curr = curr.substr(0, pos);
                if(memo.find(curr) != memo.end()){
                    found = true;
                    break;
                }
            }

            if(!found){
                answer.push_back(currFolder);
            }
        }

        return answer;
    }
};