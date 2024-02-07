//https://leetcode.com/problems/sort-characters-by-frequency/
// logic  - simple frequency based sorting if frequency is same then use lexiographical order of alphabets

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(char c: s)m[c]++;
        sort(s.begin(),s.end(),[&](char a,char c){
            if(m[a]!=m[c]){
                return m[a]> m[c];
            }
            else{
                return a<c;
            }
        });
        return s;
    }
};

// Time Complexity - O(n*log n);  n is length of array str
// Space Complexity - O(n);