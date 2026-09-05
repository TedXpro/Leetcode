class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int me = piles.size() - 2;
        int bob = 0;
        int maximum = 0;
        
        while(bob < me){
           maximum += piles[me];
           me -= 2;
           bob++;
        }
        return maximum;
    }
};