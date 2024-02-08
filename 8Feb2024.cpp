//https://leetcode.com/problems/perfect-squares/
//logic - simple recursion & optimize using dp

// 1 memoization

class Solution {
public:
    int f(int n,vector<int> &dp){
        if(n<0){
            return 1e7;
        }
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
        int mn = INT_MAX;
        for(int j = 1; j*j<=n; j++){
            int c = 1+f(n-j*j,dp);
            mn = min(mn,c);
        }
        return dp[n] = mn;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};



// Time complexity - O(n*sqrt(n));
// Space complexity - O(n);