class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        struct Meeting {
            int start;
            int end;
        };
        
        // Custom comparator to sort meetings by end time
        auto cmp = [](const Meeting& a, const Meeting& b) {
            return a.end < b.end;
        };

        int n = start.size();
        vector<Meeting> meetings(n);
        
        for (int i = 0; i < n; ++i) {
            meetings[i] = {start[i], end[i]};
        }

        sort(meetings.begin(), meetings.end(), cmp);

        int count = 1;
        int lastEnd = meetings[0].end;
        
        for (int i = 1; i < n; ++i) {
            if (meetings[i].start > lastEnd) {
                ++count;
                lastEnd = meetings[i].end;
            }
        }

        return count;
    }
};
