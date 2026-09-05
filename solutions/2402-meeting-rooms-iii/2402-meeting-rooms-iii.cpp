class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> availTime(n, 0);
        vector<int> meetingCount(n, 0);
        
        sort(meetings.begin(), meetings.end());
        for(auto& meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];
            long long minRoomAvailTime = LLONG_MAX;
            int roomAvail = 0;
            bool foundRoom = false;

            for(int i = 0; i < n; i++){
                if(availTime[i] <= start){
                    foundRoom = true;
                    meetingCount[i]++;
                    availTime[i] = end;
                    break;
                }

                if(minRoomAvailTime > availTime[i]){
                    minRoomAvailTime = availTime[i];
                    roomAvail = i;
                }
            }

            if(!foundRoom){
                availTime[roomAvail] += end - start;
                meetingCount[roomAvail]++;
            }
        }

        int maxMeetingCount = 0, maxRoomCount = 0;
        for(int i = 0; i < n; i++){
            if(meetingCount[i] > maxMeetingCount){
                maxMeetingCount = meetingCount[i];
                maxRoomCount = i;
            }
        }
        return maxRoomCount;
    }
};