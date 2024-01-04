//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        bool flag = false;
        for(auto j: m){
            flag |= (j.second==1);
            ans +=(j.second + 2)/3;
        }

        if(flag)return -1;

        return ans;

    }
};



// Time Complexity -> O(nlog(n)) 
// Space Complexity -> o(n)