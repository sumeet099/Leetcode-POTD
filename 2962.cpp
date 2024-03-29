//https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long ans = 0;
        
        int n = nums.size();
        vector<long long> dp(n,0); 
        int mx = *max_element(nums.begin(),nums.end());
        
        for(int i= 0; i<n; i++){
            
            if(i>0)
            dp[i] = dp[i-1];
            
            if(nums[i]==mx){
                 dp[i]++;
            }
        }
      
          for(int i = 0; i <n; i++){
            
            long long req = 0;
            if(i> 0)req = dp[i-1];
            
            req +=k;
            
            int l = lower_bound(dp.begin(),dp.end(),req) - dp.begin();
            ans+= (long long ) n - l;
        }
        
        
        return ans;
    }
};

// Time Complexity = O(N * log(N) ) 
// Space Complexity = O(N)

