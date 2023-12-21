class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        for(int i = 0; i < dist.size(); i++){
            time.push_back((double)dist[i] / speed[i]);
        }

        sort(time.begin(), time.end());
        int i = 0;
        for(; i < time.size(); i++){
            if(i >= time[i])
                break;
        }

        return i;
    }
};