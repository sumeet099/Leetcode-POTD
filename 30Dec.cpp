
// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        
        vector<int> v(26,0);

        for(string x: words){
            for(char y : x)v[y-'a']++;
        }

        set<int> s;

        for(auto x: v)if(x!=0)s.insert(x);

        for(auto x: s)if(x % n!=0)return false;

        return true;
    }
};

// Time Complexity : O(n*k)  where k is length of a string
// Space Complexity : O(26)  