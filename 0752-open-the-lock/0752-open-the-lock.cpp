class Solution {
private:
    class Locks{
    private:
        string lock; 
        int turns;
    public:
        Locks(string l, int t){
            lock = l;
            turns = t;
        }

        string getLock(){
            return lock;
        }

        int getTurns(){
            return turns;
        }
    };

    vector<string> generateLocks(string lock){
        vector<string> posLocks;
        for(int i = 0; i < 4; i++){
            int n = lock[i] - '0';
            int num = (n + 1) % 10;
            string l = lock.substr(0, i) + to_string(num) + lock.substr(i + 1);
            posLocks.push_back(l);

            num = (n - 1 + 10) % 10;
            l = lock.substr(0, i) + to_string(num) + lock.substr(i + 1);
            posLocks.push_back(l);
        }
        return posLocks;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        deque<Locks> deq;
        unordered_set<string> visited;
        for(string &str : deadends)
            visited.insert(str);
        
        if(visited.find("0000") != visited.end())
            return -1;
        
        Locks initialLock("0000", 0);
        deq.push_back(initialLock);
        while(!deq.empty()){
            Locks lk = deq.front();
            deq.pop_front();
            string lok = lk.getLock();
            int turns = lk.getTurns();
            if( lok == target)
                return turns;
            vector<string> possibleLocks = generateLocks(lok);
            for(string &pos : possibleLocks){
                if(visited.find(pos) == visited.end()){
                    visited.insert(pos);
                    Locks currLock(pos, turns + 1);
                    deq.push_back(currLock);
                }
            }
        }
        return -1;
    }
};