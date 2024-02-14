//https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// 1. Brute Force Approach

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(auto x: nums){
            if(x<0)neg.push_back(x);
            else pos.push_back(x);
        }

        vector<int> ans;
        
        for(int i = 0; i<pos.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};

// Time Complexity - O(n)     
// Space Complexity - O(n)   

// -------------------------------------------------------------------------------------

// 2.Two Pointers Apporach

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> ans(nums.size(),0);

       int i=0,j = 1;

       for(auto x: nums){
          if(x>=0){
              ans[i] = x;
              i+=2;
          }
          else{
              ans[j] = x;
              j+=2;
          }
       }
       return ans;
    }
};


// Time Complexity - O(n)     
// Space Complexity - O(1)   
