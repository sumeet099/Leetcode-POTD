//https://leetcode.com/problems/partition-array-for-maximum-sum/
//logic - partition dp
		// try to explore all ways and choose best answer and use dp to optimize solution


// 1) Memoization

class Solution {
public:
    int f(int ind,vector<int>&arr,vector<int>&dp,int k,int n){
        if(ind==n)return 0;

        if(dp[ind]!=-1)return dp[ind];
        int maxAns = 0;
        int maxi =0;
        int len=0;
        for(int j = ind; j<min(n,ind+k); j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len * maxi + f(j+1,arr,dp,k,n);
            maxAns = max(maxAns,sum);
        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,dp,k,n);
    }
};

// Time Complexity - O(n*k);
// Space Complexity - O(n); (includes auxiliary stack space + recursion stack space)



// 2) tabulation

class Solution {
public:
   
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int ind = n-1; ind>=0; ind--){
            int maxAns = 0;
            int maxi =0;
            int len=0;
            for(int j = ind; j<min(n,ind+k); j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = len * maxi + dp[j+1];
                maxAns = max(maxAns,sum);
            }
            dp[ind] = maxAns;
        }
        return dp[0];
    }
};

// Time Complexity - O(n*k);
// Space Complexity - O(n); (includes only auxiliary stack space )



//tabulation with space optimization

class Solution {
public:
    int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
        int n = arr.size();
        std::vector<int> dp(k, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            int maxAns = 0;
            int maxi = 0;
            int len = 0;

            for (int j = ind; j < std::min(n, ind + k); j++) {
                len++;
                maxi = std::max(maxi, arr[j]);
                int sum = len * maxi + (j + 1 < n ? dp[(j + 1) % k] : 0);
                maxAns = std::max(maxAns, sum);
            }

            dp[ind % k] = maxAns;
        }

        return dp[0];
    }
};

// Time Complexity - O(n*k);
// Space Complexity - O(k); (includes only auxiliary stack space )