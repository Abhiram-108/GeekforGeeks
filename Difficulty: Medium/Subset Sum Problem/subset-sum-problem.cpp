class Solution {
private:
    int help(vector<int>& a, vector<vector<int>>& dp, int sum, int index) {
        if (sum == 0)
            return 1;
        if (index == 0)
            return a[0] == sum;
        if (dp[index][sum] != -1)
            return dp[index][sum];

        int notpick = help(a, dp, sum, index - 1);
        int pick = 0;
        if (a[index] <= sum)
            pick = help(a, dp, sum - a[index], index - 1);

        return dp[index][sum] = pick || notpick;
    }

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // Bit manipulation approach (works well for n <= 20)
        /*
        int n = arr.size();
        int totalSubsets = 1 << n;
        for (int mask = 0; mask < totalSubsets; mask++) {
            int currSum = 0;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    currSum += arr[j];
                }
            }
            if (currSum == sum)
                return true;
        }
        return false;
        */

        // Recursive DP approach (top-down)
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return help(arr, dp, sum, n - 1);
    }
};
