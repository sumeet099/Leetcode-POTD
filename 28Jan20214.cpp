//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/


//kind of brute Force solution but accepted hardly
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat , int target) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> preCompute(n+1,vector<int>(m+1,0));
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

         for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                preCompute[i][j] = mat[i-1][j-1];
            }
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                preCompute[i][j] += preCompute[i][j-1];
                dp[i][j] = preCompute[i][j] + dp[i-1][j]; 
            }
        }
       
        int ans = 0;
        for(int i1 = 1; i1<=n; i1++){
            for(int j1 = 1; j1<=m; j1++){

                for(int i2 = 1; i2<=n; i2++){
                    for(int j2 = 1; j2<=m; j2++){

                        if(i1<=i2 && j1<=j2){
                        long long int s = dp[i2][j2] + dp[i1-1][j1-1] - dp[i1-1][j2] - dp[i2][j1-1];
                            if(s==target)ans++;
                        }
                    }
                }
                
            }
        }

        return ans;
    }
};


//Time Complexity - O(n*n*m*m);
//Space Complexity - O(n*m); (only auxiliary space)