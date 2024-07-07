class Solution {
public:
    int dp[2001];
    int mini = INT_MAX;
    bool isPal(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int solve(string& s, int idx, int n) {
        if (idx == n) {
            return 0;
        }
        if(dp[idx]!=-1)
            return dp[idx];
        if (isPal(s, idx, n - 1)) {
            return 0;
        }
        int minCuts = INT_MAX;
        for (int i = idx; i < n; i++) {
            if (isPal(s, idx, i)) {
                minCuts = min(minCuts, 1 + solve(s, i + 1, n));
            }
        }
        return dp[idx]= minCuts;
    }
    int minCut(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        if (n <= 1) return 0; 
        mini = solve(s, 0, n);
        return mini; 
    }
};
