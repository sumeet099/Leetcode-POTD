//https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& num, int k) {
        vector<vector<int>> ans;
        int n = (int)num.size();
        if(n % 3)return ans;

        vector<int> nums = num;
        sort(nums.begin(),nums.end());
        for(int i = 0; i+2<n; i+=3){
            if((nums[i+2]-nums[i])>k){
                return {};
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }

        return ans;
    }
};

// Time Complexity - O(nlogn);

// Space Complexity - O(n)   ( if input array is changed - O(1))