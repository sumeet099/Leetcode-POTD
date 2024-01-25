//https://leetcode.com/problems/longest-common-subsequence/
// logic - dynamic programming

//memoization
class Solution {
public:
    int dp[1001][1001];
    int lcs(int i,int j,string &a,string &b){

        if(i==0 || j==0){
            return 0;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        if(a[i-1]==b[j-1]){
            return 1 + lcs(i-1,j-1,a,b);
        }

        return dp[i][j] = max(lcs(i-1,j,a,b),lcs(i,j-1,a,b));
        
    }
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        memset(dp,-1,sizeof(dp));
        return lcs(n,m,a,b);
    }
};
//Time Complexity - O(N*M);
//Space Complexity - O(N*M);



// tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       
        for(int i = 1; i<=n ;i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] =  1 +dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};

//Time Complexity - O(N*M);
//Space Complexity - O(N*M);



//Tabulation with space Optimization

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> cur(m+1,0),prev(m+1,0);
       
        for(int i = 1; i<=n ;i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    cur[j] =  1 +prev[j-1];
                }
                else{
                    cur[j] = max(prev[j],cur[j-1]);
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};
//Time Complexity - O(N*M);
//Space Complexity - O(M);