
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> m(n+1,0);

        for(auto x: nums){
            m[x]++;
        }
        vector<vector<int>> ans;
        bool flag = true;

        while(true){
            flag = false;
            vector<int> c;
            for(int i = 0;i<=n;i++){
                if(m[i]>0){
                    flag = true;
                    m[i]--;
                    c.push_back(i);
                }
            }
            if(!flag)break;
            ans.push_back(c);
        }
        return ans;
    }
};

// My approach - brute force 
// Time Complexity: O(n*f)  where f is the maximum frequency of any element  

// Space Complexity : O(n)      



// editorial solution - optimized in O(N) time

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size()+1);

        vector<vector<int>> ans;

        for(int c: nums){
            if(freq[c]>= ans.size()){
                ans.push_back({});
            }
            ans[freq[c]].push_back(c);
            freq[c]++;
        }   

        return ans;
    }
};

// logic - it is a simple fact that we need array size as the max frequency of any element so initialized into ans array according to the frequency
// Time complexity -> O(n) single pass
// Space Complexity -> O(n) 
