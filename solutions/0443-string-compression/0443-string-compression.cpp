class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0, end = 0;
        for(; end < chars.size(); end++){
            int count = 1;
            while(end + 1 < chars.size() && chars[start] == chars[end + 1]){
                count++;
                end++;
            }

            if(count == 1){
                start++;  
                if(end + 1 < chars.size())
                chars[start] = chars[end + 1];        
                continue;
            }
            string c = to_string(count);
            for(int i = 0; i < c.length(); i++){
                chars[++start] = c[i];
            }
            start++;
            if(end + 1 < chars.size())
                chars[start] = chars[end + 1];
        }

        return start;
    }
};