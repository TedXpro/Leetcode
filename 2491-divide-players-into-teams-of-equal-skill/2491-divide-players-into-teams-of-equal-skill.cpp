class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int size = skill.size();
        int num = skill[0] + skill[size - 1];
        long long chem = skill[0] * skill[size - 1];
        for(int i = 1, j = size - 2; i < j; i++, j--){
            if(skill[i] + skill[j] != num){
                return -1;
            }
            chem += skill[i] * skill[j];
        }

        return chem;
    }
};