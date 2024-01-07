// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
//logic - 
        //it is simple that  dp[i][j] represent number of arithmetic subsequences ending at index i with a common difference of j
        //total_count stores all arithmetic subsequences in array (required answer = total_count)
        //  Iterate through the array nums with two nested loops:
                // The outer loop (i) goes from 1 to n - 1.
                // The inner loop (j) goes from 0 to i - 1.
        // here common difference is (diff = nums[i]-nums[j]) 
        // so if there exists common difference (diff) at index  j then extend it for index i by Increment dp[i][diff] by the value of dp[j][diff]
        // and Update the total_count by adding the value of dp[j][diff] to it.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int total_count  = 0;
        vector<unordered_map<int,int>> dp(n);
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                long long int diff = 1LL*nums[i]-1LL*nums[j];
                if(diff>INT_MAX || diff<INT_MIN)continue;
                dp[i][diff]+=1;

                if(dp[j].count(diff)){
                    dp[i][diff] += dp[j][diff];
                    total_count += dp[j][diff];
                }

            }
        }

        return total_count;
    }
};

// Time Complexity - O(n*n) (nested for loop)
// Space Complexity - O(n*n) (dp array)