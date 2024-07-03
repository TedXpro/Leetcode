class Solution {
    int find(vector<int> &parent, int x){
        if(parent[x] != x){
            return find(parent, parent[x]);
        }
        return x;
    }

    bool unionF(vector<int> &parent, vector<int> &rank, int x1, int x2){
        int x1p = find(parent, x1), x2p = find(parent, x2);
        if(x1p == x2p){
            return false;
        }
    
        if(rank[x1p] > rank[x2p]){
            parent[x2p] = x1p;
            rank[x1p] += rank[x2p];
        } else {
            parent[x1p] = x2p;
            rank[x2p] += rank[x1p];
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1);
        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }

        vector<int> rank(edges.size() + 1, 1);
        vector<int> answer;
        for(vector<int> &edge : edges){
            if(!unionF(parent, rank, edge[0], edge[1])){
                answer = edge;
                break;
            }
        }
        return answer;
    }
};