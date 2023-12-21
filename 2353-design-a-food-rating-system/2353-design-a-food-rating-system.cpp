class FoodRatings {
private:
    class Rating{
    public:
        string food;
        int rate;
    
        Rating(string f, int r){
            food = f;
            rate = r;
        }    

        bool operator<(const Rating& other) const{
            if(rate == other.rate)
                return food > other.food;
            return rate < other.rate;
        }
    };

    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, priority_queue<Rating>> bestFood;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            bestFood[cuisines[i]].push(Rating(foods[i], ratings[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRatingMap[food] = newRating;
        bestFood[foodCuisineMap[food]].push(Rating(food, newRating));
    }
    
    string highestRated(string cuisine) {
        auto highestRated = bestFood[cuisine].top();

        while(foodRatingMap[highestRated.food] != highestRated.rate){
            bestFood[cuisine].pop();
            highestRated = bestFood[cuisine].top();
        }
        return highestRated.food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */