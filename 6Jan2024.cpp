//https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
//logic ->
    // we have to do pick/notpick for all jobs 
    // binary search is used to get nextIndex so that we will not explore all possibility 
    // so that sorting jobs intially helps to apply binary search  
    // this problem can be done in n*n time but due to constraint nlogn is optimized 

class Solution {
public:
    int dp[50001];
    int findMaxProfit(vector<vector<int>> &jobs,vector<int>&start,int n,int ind){
        if(ind==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int nextIndex  = lower_bound(start.begin(),start.end(),jobs[ind][1]) - start.begin();

        int maxProfit = max(findMaxProfit(jobs,start,n,ind+1),jobs[ind][2] + findMaxProfit(jobs,start,n,nextIndex));
        return dp[ind]= maxProfit;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> jobs;
        for(int i = 0; i<n; i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());
        for(int i= 0;i<n ; i++){
            startTime[i] = jobs[i][0];
        }
        return findMaxProfit(jobs,startTime,n,0);
    }
};


// Time Complexity -> O(N log(N))
// Space Complexity -> O(N)