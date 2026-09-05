class Solution {
private:
    static bool compare(string &a, string& b){
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numbers (nums.size());
        for(int i = 0; i < nums.size(); i++)
            numbers[i] = to_string(nums[i]);
        
        sort(numbers.begin(), numbers.end(), compare);
        if(numbers[0] == "0")
            return "0";
            
        string answer = "";
        for(string number : numbers)
            answer += number;
        
        return answer;
    }
};