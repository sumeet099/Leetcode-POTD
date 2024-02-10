//https://leetcode.com/problems/palindromic-substrings/description/


// very brute force solution

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
    int countSubstrings(string s) {
        int  n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            string c = "";
            for(int j = i; j<n; j++){ 
                c+=s[j];                 
                if(isPalindrome(c)){
                    ans++;
                }
           }
        }
        return ans;
    }
};

// Time complexity - O(n*n*n)
// Space complexity - O(1);



// Memoization

class Solution {
public:
    int isPalindrome(int i,int j,string&s,vector<vector<int>>&dp){
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = (s[i]==s[j] ? isPalindrome(i+1,j-1,s,dp) : 0);
    }
    int countSubstrings(string s) {
        int  n = s.size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                ans+= isPalindrome(i,j,s,dp);
            }
        }
        return ans;
    }
    
};
// Time complexity - O(n*n)
// Space complexity - O(n*n);  //recursion stack space



//tabulation

class Solution {
public:
     
    int countSubstrings(string s) {
        int  n = s.size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1));

       
        for(int i = n; i>=0; i--){
            for(int j = i; j<n; j++){
                 if(i==j){
                     dp[i][j] = 1;
                 }
                 else if(j-i==1){
                     dp[i][j] = s[i]==s[j];
                 }
                 else{
                     if(s[i]==s[j]){
                         dp[i][j] = dp[i+1][j-1];
                     }
                     else{
                         dp[i][j] = 0;
                     }
                 }
                ans+= dp[i][j];
            }
        }
        return ans;
    }
    
};
// Time complexity - O(n*n)
// Space complexity - O(n*n);  //no recursion stack space


// observation

class Solution {
public:
    int countPalindrome(string&s,int start,int end){
        int count = 0;
        int n = s.size();
        while(start>=0 && end<n && s[start]==s[end]){
            start--; end++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            int evenLength = countPalindrome(s,i,i+1);
            int oddLength = countPalindrome(s,i,i); 
            ans+= evenLength + oddLength; 
        }
        return ans;
    }
};

// Time complexity - O(n*n)
// Space complexity - O(1);