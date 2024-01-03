
//https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        long long int ans =0;
        int prev = 0;

        for(string &s : bank){
            int ct = count(s.begin(),s.end(),'1');  
            if(ct>0){
                ans+= 1LL * prev * ct;
                prev = ct;
            }
        }        
        
        return ans;
    }
};

// my approach is similar to editorial (also optimized one)

// Time Complexity -> O(m*n) where m is length of string and n is length of array
// Space Complexity -> O(1)  (constant space)