//https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

//using Reverse String
class Solution {
public:

    string firstPalindrome(vector<string>& words) {
        for(auto x: words){
            string y = x; 
            reverse(y.begin(),y.end());
            if(x==y)return x;
        }        
        return "";
    }
};

// Time Complexity - O(n *m )    // where m is length of string & n is length of string array
// Space Complexity - O(m)    

//using Two Pointers Approach
class Solution {
public:
      bool isPalindrome(string &c){
        int i = 0,j= c.size()-1;
        while(i<j){
            if(c[i]!=c[j])return false;
            i++; j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto x: words){
            if(isPalindrome(x))return x;
        }        
        return "";
    }
};


// Time Complexity - O(n *m )    // where m is length of string & n is length of string array
// Space Complexity - O(1)    