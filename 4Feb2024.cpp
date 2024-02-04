//https://leetcode.com/problems/minimum-window-substring/
//logic - simple sliding window but implementation is best part to learn (I was not able to solve initially but after practice it is well understood)
class Solution {
public:
    
    string minWindow(string s, string t) {
        int n = s.size();
        if(s.empty()|| t.empty()){
            return "";
        }
        if(t.size()>s.size()){
            return "";
        }

        unordered_map<char,int> mp;

        for(char &ch : t){
            mp[ch]++;
        }

        int requiredCount  = t.size();
        int i = 0,j = 0;

        int minWindow_Size = INT_MAX;
        int start_i = i;

        while(j<n){

            char ch = s[j];

            if(mp[ch]>0){
                requiredCount--;
            }
            mp[ch]--;


            while(requiredCount==0){
                //shriking start
                int currWindow_Size = j-i+1;

                if(currWindow_Size < minWindow_Size){
                    minWindow_Size = currWindow_Size;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }

            j++;
        }
        return minWindow_Size == INT_MAX ? "" : s.substr(start_i,minWindow_Size);

    }
};



// Time Complexity - O(n+m);
// Space Complexity - O(26);
