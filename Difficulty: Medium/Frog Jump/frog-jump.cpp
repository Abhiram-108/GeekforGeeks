class Solution {
public:
    int minCost(vector<int>& h) {
        int n = h.size();
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = abs(h[1] - h[0]);
        
        for (int i = 2; i < n; i++) {
            int jumpOne = dp[i - 1] + abs(h[i] - h[i - 1]);
            int jumpTwo = dp[i - 2] + abs(h[i] - h[i - 2]);
            dp[i] = min(jumpOne, jumpTwo);
        }
        return dp[n - 1];
    }
};
