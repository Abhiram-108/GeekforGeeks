class Solution {
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        return a.second < b.second; // sort by end time
    }
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> a;
        int n = start.size();
        for (int i = 0; i < n; i++) {
            a.push_back({start[i], end[i]});
        }
        
        sort(a.begin(), a.end(), cmp);
        
        int ct = 1; 
        auto it1 = a[0]; // take first meeting
        
        for (int i = 1; i < n; i++) {
            auto it2 = a[i];
            if (it2.first > it1.second) { // no overlap
                ct++;
                it1 = it2;
            }
        }
        return ct;
    }
};
