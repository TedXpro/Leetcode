class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long, vector<long long>> pq(gifts.begin(), gifts.end());

        while(k > 0){
            int curr = pq.top();
            cout << curr << " : ";
            pq.pop();
            curr = sqrt(curr);
            cout << curr << endl;
            pq.push(curr);
            k--;
        }

        long long answer = 0;
        while(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }

        return answer;
    }
};