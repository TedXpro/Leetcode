class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int, greater<char>> memo;
        for(char ch : s){
            memo[ch]++;
        }

        string answer = "";
        
        while(!memo.empty()){
            auto itr = memo.begin();
            cout << "Current: " << itr->first << " ##### " << itr->second << endl;
            int count = 0;
            for(int i = 0; i < itr->second; i++){
                answer += itr->first;
                count++;
                if((i + 1 != itr->second) && count == repeatLimit){
                    if(memo.size() == 1){
                        return answer;
                    }
                    answer += next(itr)->first;
                    next(itr)->second--;
                    if(next(itr) -> second == 0){
                        memo.erase(next(itr));
                    }
                    count = 0;
                }
            }
            cout << "CurrentAnswer : ===== " << answer << endl;

            memo.erase(itr);
        }

        return answer;
    }
};