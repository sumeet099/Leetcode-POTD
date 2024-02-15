//https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = -1;
        long long sum = 0;
        for(auto &x: nums){
            if(sum > x){
                ans = sum+x;
            }
            sum+= x;
        }
        return ans;
    }
};



// Time Complexity - O(n log(n))     
// Space Complexity - O(1)   
