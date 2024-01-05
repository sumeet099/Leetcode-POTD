// https://leetcode.com/problems/longest-increasing-subsequence/description/
//logic -> simple dp  i.e. (pick-notpick)
//imp -> handling prev intially it's -1 there by co -ordinate shift i.e (prev+1) instead of prev

class Solution {
public:
    
    int f(int i,int prev,vector<int>&arr,vector<vector<int>> &dp,int n){

        if(i==n){
            return 0;
        }
        
        
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int pick = 0;
        
        if((prev==-1 )|| (arr[i] > arr[prev])){
            pick = 1 + f(i+1,i,arr,dp,n);
        }

        int notpick = f(i+1,prev,arr,dp,n);

        return dp[i][prev+1] = max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        return f(0,-1,nums,dp,n);
    }
};

// Time complexity -> O(n*n)
// Space complexity -> O(n*n) (dp array) + O(n) (Auxiliary stack space)