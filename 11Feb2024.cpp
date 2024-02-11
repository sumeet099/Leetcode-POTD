//https://leetcode.com/problems/cherry-pickup-ii/description/
//logic - explore all paths and optimize using dp

class Solution {
public:
    int f(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){

        if(j1<0 || j1>=m || j2<0 || j2>=m){
            return -1e9;
        }
        
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

        if(i==n-1){
            return dp[i][j1][j2] = (j1==j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
        }

        int maxi = -1e9;

        for(int y1 = -1; y1<=1; y1++){

            for(int y2 = -1; y2<=1; y2++){
                
                int value = 0;
                if(j1==j2){
                    value = grid[i][j1];
                }
                else{
                    value = grid[i][j1] + grid[i][j2];
                }
                value += f(i+1,j1+y1,j2+y2,n,m,grid,dp);
                maxi = max(maxi,value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return f(0,0,m-1,n,m,grid,dp);   
    }
};


// Time Complexity - O(n*m*m)
// Space Complexity - O(n*m*m)