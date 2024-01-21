//https://leetcode.com/problems/house-robber/

// logic - Use 2-d Dynamic Programming 
		// - dp[i][j] denotes till index i if state is j then what is the maximum answer you will get by trying all possible ways

class Solution {
public:
    int solve(int idx,int prev,vector<vector<int>>& dp,vector<int>&nums){
        if(idx<0){
            return 0;
        }
        
        if(dp[idx][prev]!=-1)return dp[idx][prev];

        int pick = 0;
        if(prev==0){
            pick = nums[idx] + solve(idx-1,1,dp,nums);
        }

        // notpick

        int notpick = solve(idx-1,0,dp,nums);

        return dp[idx][prev] = max(notpick,pick);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(n-1,0,dp,nums);
    }
};



//Time Complexity - O(N*2);
//Space Complexity - O(N*2) + O(N*2)(recursion stack space) ==>  O(N*2) 