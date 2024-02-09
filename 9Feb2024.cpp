//https://leetcode.com/problems/largest-divisible-subset/
// 	logic -  //we will be using the exactly same concept that we have used in longest increasing subsequence
			 // extra condition is (nums[i]%nums[j]==0) else as it is like LIS

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),prevIndex(n,-1);

        int maxLength = 0;
        int index = 0;

        sort(nums.begin(),nums.end());

        for(int i = 0; i<n;i++){
            for(int j =0; j<i; j++){

                if((nums[i] % nums[j]==0) && (1+dp[j]>dp[i])){
                    dp[i] = 1+ dp[j];
                    prevIndex[i] = j;
                }
            }
            if(dp[i]> maxLength){
                maxLength = dp[i];
                index = i;
            }

        }

        vector<int> ans;

        while(index!=-1){
            ans.push_back(nums[index]);
            index = prevIndex[index];
        }

        return ans;
    }
};


// Time complexity - O(n*n)
// Space complexity - O(n);