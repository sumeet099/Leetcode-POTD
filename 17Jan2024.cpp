//https://leetcode.com/problems/unique-number-of-occurrences/description/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq,uniqueFreq;

        for(auto &x: arr){
            freq[x]++;
        }
        for(auto &x : freq){
            uniqueFreq[x.second]++;
        }
        return freq.size() == uniqueFreq.size();
    }
};


// Time Complexity -  O(N log N)
// Space Complexity - O(N)