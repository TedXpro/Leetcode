class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> flightMap;
        vector<string> result;

        for (const auto& ticket : tickets) {
            flightMap[ticket[0]].insert(ticket[1]);
        }

        dfsTraversal("JFK", flightMap, result);
        reverse(result.begin(), result.end());

        return result;
    }

private:
    void dfsTraversal(const string& current,
                      unordered_map<string, multiset<string>>& flightMap,
                      vector<string>& result) {
        auto& destinations = flightMap[current];

        while (!destinations.empty()) {
            auto nextDestination = *destinations.begin();
            destinations.erase(destinations.begin());

            dfsTraversal(nextDestination, flightMap, result);
        }

        result.push_back(current);
    }
};