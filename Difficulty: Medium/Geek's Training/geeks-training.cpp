class Solution {
private:
    int help(vector<vector<int>>& dp, vector<vector<int>>& a, int day, int last) {
        if (day == 0) {
            int maxi = 0;
            for (int index = 0; index < 3; index++) {
                if (index != last) {
                    maxi = max(maxi, a[0][index]);
                }
            }
            return dp[day][last] = maxi;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;
        for (int index = 0; index < 3; index++) {
            if (index != last) {
                int activity = a[day][index] + help(dp, a, day - 1, index);
                maxi = max(maxi, activity);
            }
        }

        return dp[day][last] = maxi;
    }

public:
    int maximumPoints(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return help(dp, a, n - 1, 3); // last = 3 means no task was done the previous day
    }
};
