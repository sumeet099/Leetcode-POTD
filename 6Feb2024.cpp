//https://leetcode.com/problems/group-anagrams/
// logic -  simple brute force


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagramGroups;

    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());

        anagramGroups[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;

    }
};


// Time Complexity - O(n*m *log m);  n is length of array str &  m is length of individual string of string array
// Space Complexity - O(n);


//optimized - just use concept of total number of alphabets is 26 so use frequency array of size 26

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        map<vector<int>,vector<int>> m;
        for(int i = 0; i<str.size(); i++){
            vector<int> freq(26,0);
            for(auto j: str[i]){
                freq[j-'a']++;
            }
            m[freq].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto x: m){
            vector<string> temp;
            for(auto y: x.second){
                temp.push_back(str[y]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Time Complexity - O(n*26);  n is length of array str
// Space Complexity - O(26*n);