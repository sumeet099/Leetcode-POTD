//https://leetcode.com/problems/k-inverse-pairs-array/description/

//tabulation 
class Solution {
public:
    using ll = long long int;
    const ll mod = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
        dp[0][0] = 1;
        for(ll i= 1; i<=n; i++){
            ll val = 0;
            for(int j = 0; j<=k; j++){
                val += dp[i-1][j];
                if(j>=i){
                    val-=dp[i-1][j-i];
                }
                dp[i][j] = val % mod;
                dp[i][j] %= mod;
            }
            cout<<endl;
        }

        return dp[n][k];

    }
};
//Time Complexity - O(n*k);
//Space Complexity - O(n*k); (only auxiliary space)


//tabulation with space optimization
class Solution {
public:
    using ll = long long int;
    const ll mod = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<long long> cur(k+1,0),prev(k+1,0);
        prev[0] = 1;
        for(ll i= 1; i<=n; i++){
            ll val = 0;
            for(int j = 0; j<=k; j++){
                val += prev[j];
                if(j>=i){
                    val-=prev[j-i];
                }
                cur[j] = val % mod;
                cur[j] %= mod;
            }
            prev = cur;
        }

        return prev[k];

    }
};

//Time Complexity - O(n*k);
//Space Complexity - O(k); (only auxiliary space)