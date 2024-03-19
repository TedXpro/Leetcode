class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> memo(26, 0);
        int maximum = 0, maxCount = 0;
        for(char &ch : tasks){
            memo[ch - 'A']++;
            if(maximum == memo[ch - 'A'])
                maxCount++;
            else if(maximum < memo[ch - 'A']){
                maximum = memo[ch - 'A'];
                maxCount = 1;
            }
        }

        int count = maximum - 1;
        int length = n - (maxCount - 1);
        int emptySlots = count * length;
        int availTasks = tasks.size() - maximum * maxCount;
        int idles = max(0, emptySlots - availTasks);
        
        return tasks.size() + idles;
    }
};