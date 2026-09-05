class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> heap;
        if(a > 0) {
            heap.push({a, 'a'});
        }

        if(b > 0){
            heap.push({b, 'b'});
        }

        if(c > 0){
            heap.push({c, 'c'});
        }

        string answer = "";
        while(!heap.empty()){
            pair<int, char> curr = heap.top();
            heap.pop();
            int count = curr.first;
            char ch = curr.second;

            if(answer.length() >= 2 && answer[answer.length() - 1] == ch && answer[answer.length() - 2] == ch){
                if(heap.empty()){
                    break;
                }

                pair<int, char> secondLargest = heap.top();
                heap.pop();
                answer += secondLargest.second;
                if(secondLargest.first - 1 > 0){
                    heap.push({secondLargest.first - 1, secondLargest.second});
                }
            } else {
                count--;
                answer += ch;
            }

            if(count > 0){
                heap.push({count, ch});
            }
        }

        return answer;
    }
};