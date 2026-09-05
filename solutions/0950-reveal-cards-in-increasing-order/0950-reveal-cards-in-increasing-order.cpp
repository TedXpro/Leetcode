class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> answer(deck.size(), 0);
        int answerIndex = 0, deckIndex = 0;
        bool skip = false;

        sort(deck.begin(), deck.end());
        while(deckIndex < deck.size()){
            if(answer[answerIndex] == 0){
                if(!skip)
                    answer[answerIndex] = deck[deckIndex++];
                skip = !skip;
            }
            answerIndex = (answerIndex + 1) % deck.size();
        }

        return answer;
    }
};