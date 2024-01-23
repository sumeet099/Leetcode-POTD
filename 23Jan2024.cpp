
//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
// logic - try all possible combinations

class Solution {
public:
    bool canPick(string temp,string s){
        unordered_set<char>us(temp.begin(),temp.end());
        if(us.size()!=temp.size())return false;
        for(auto c:s){
            if(us.find(c)!=us.end())return false;
        }
        return true;
    }

    int f(int i,string s,vector<string>&arr){
        if(i<0)return s.size();
        int pick = 0;
        if(canPick(arr[i],s))pick = f(i-1,s+arr[i],arr);

        int notPick = f(i-1,s,arr);
        return max(pick,notPick);
    }
    int maxLength(vector<string>& arr) {
        string s = "";
        return f(arr.size()-1, s,arr);
    }
};


//Time Complexity - O(2^N);
//Space Complexity - O(N);
