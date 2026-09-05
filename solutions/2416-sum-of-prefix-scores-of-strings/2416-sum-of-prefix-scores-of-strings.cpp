class Solution {
private:
    struct TrieNode{
        TrieNode* children[26] = {};
        int count = 0;
    };
    TrieNode root;

    void insert(string word){
        TrieNode* node = &root;
        for(char ch : word){
            if(!node->children[ch - 'a']){
                node->children[ch - 'a'] = new TrieNode();
            }
            node->children[ch - 'a']->count++;
            node = node->children[ch - 'a'];
        }
    }

    int count(string s){
        TrieNode* node = &root;
        int ans = 0;
        for(char ch : s){
            ans += node->children[ch - 'a']->count;
            node = node->children[ch - 'a'];
        }

        return ans;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string word : words){
            insert(word);
        }

        vector<int> answer;
        for(string word : words){
            answer.push_back(count(word));
        }

        return answer;
    }
};