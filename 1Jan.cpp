//https://leetcode.com/problems/assign-cookies/description/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        multiset<int> m;
        for(auto x: s){
            m.insert(x);
        }

        sort(g.begin(),g.end());

        int ans =0;

        for(auto x: g){

            auto it = m.lower_bound(x);

            if(it==m.end()){
                break;
            }
            m.erase(it);
            ans+=1;
        }

        return ans;
    }
};

// Time Complexity : O(n*logn)  
//  -- log(n) operation for binary search & erasing element from set 
//  -- for sorting also (no need but it's okay bcz any way TC is nlogn)

// Space Complexity : O(n)  
