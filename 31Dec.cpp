
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        vector<pair<int,int>> v(26,{-1,-1});

        for(int i = 0; i<s.size(); i++){
            
            int c = s[i] -'a';
            
            if(v[c].first!=-1){
                v[c].second = i;
            }
            else{
                v[c].first =  i;
            }

        }

        int ans = -1;

        for(int i=0;i<26;i++){
            ans = max(ans, (v[i].second - v[i].first -1));
        }

        return ans;
    }
};

// Time Complexity : O(n)    
// Space Complexity : O(26) - for storing first & last occurence of character in a string  