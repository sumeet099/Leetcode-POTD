//https://leetcode.com/problems/out-of-boundary-paths/description/
// logic - try all possible path using dp

class Solution {
public:
    using ll =long long ;
    const ll mod = 1e9+7;
    ll dp[51][51][51];
     ll findPaths1(ll m, ll n, ll maxMove, ll startRow, ll startColumn) {
        if(startRow==m ||startRow<0 ||startColumn==n || startColumn<0)return 1;
        if(maxMove==0)return 0;

        if(dp[startRow][startColumn][maxMove]!=-1)return dp[startRow][startColumn][maxMove];

       ll ans = findPaths1(m,n,maxMove-1,startRow-1,startColumn) % mod
              +findPaths1(m,n,maxMove-1,startRow+1,startColumn)% mod
              +findPaths1(m,n,maxMove-1,startRow,startColumn-1)% mod
              +findPaths1(m,n,maxMove-1,startRow,startColumn+1)% mod;
        ans %=mod;

        return dp[startRow][startColumn][maxMove]= ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i = 0;i<=50; i++)
         for(int j = 0;j<=50; j++)
          for(int k = 0;k<=50; k++)
            dp[i][j][k] = -1;
        return findPaths1(  m,   n,   maxMove,   startRow,   startColumn);
    }
};

//Time Complexity - O(N*M*maxMove);
//Space Complexity - O(N*M*maxMove) + O(N*M*maxMove);
					// recursion stack space + auxiliary space



class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {
        const int M = 1000000007;
        vector< vector<int>> dp(m,  vector<int>(n, 0));
        dp[x][y] = 1;
        int count = 0;

        for (int moves = 1; moves <= N; moves++) {
            vector<vector<int>> temp(m,  vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == m - 1) count = (count + dp[i][j]) % M;
                    if (j == n - 1) count = (count + dp[i][j]) % M;
                    if (i == 0) count = (count + dp[i][j]) % M;
                    if (j == 0) count = (count + dp[i][j]) % M;

                    temp[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % M +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M
                    ) % M;
                }
            }
            dp = temp;
        }

        return count;
    }
};


//Time Complexity - O(N*M*maxMove);
//Space Complexity - O(N*M*maxMove); (only auxiliary space)