// Date: October 6, 2023
class Solution {
unordered_map<int, int> dp;
public:
    int memo(int n) {
        if(n == 1) return 0;
        if(dp.count(n)) return dp[n];
        if(n % 2 == 0) {
            dp[n] = memo(n/2)+1;
        } else {
            if (n == INT_MIN) dp[n] = memo(n+1);
            else if (n == INT_MAX) dp[n] = memo(n-1);
            else dp[n] = min(memo(n+1)+1, memo(n-1)+1);
        }
        return dp[n];
    }
    
    int integerReplacement(int n) {
        int res = memo(n);
        return res;
    }
};
