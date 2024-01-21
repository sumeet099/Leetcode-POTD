//https://leetcode.com/problems/sum-of-subarray-minimums/

// logic -  

	//To arrive at the solution, we must track two things for each element arr[i]:

		//left[i]: the index of the first smaller element to the left of arr[i]
		//right[i]: the index of the first element that is less than or equal to arr[i] to the right
		//          With left[i] and right[i] determined, the number of subarrays in which arr[i] is 				
			  the minimum can be calculated by (i - left[i]) * (right[i] - i).

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        long long int ans  =0 ;
        int n =nums.size();
        int mod = 1e9+7;

        vector<int> left(n,-1);
        vector<int> right(n,n);

        stack<int> stk;
        for(int i = 0; i<n; i++){
            while(!stk.empty() && nums[stk.top()]>=nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk =stack<int>();

        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && nums[stk.top()]> nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                right[i] = stk.top();
            }
            stk.push(i);
        }

        for(int i = 0; i<n; i++){
            ans = (ans + 1LL* nums[i] *(i-left[i]) *(right[i]-i)) % mod;
        }

        return ans;
    }
};


//Time Complexity - O(N);
//Space Complexity - O(N);
