//https://leetcode.com/problems/find-the-town-judge/description/
//logic - use the concept of outdegree and indegree

//for better understanding solution

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<vector<int>> outdegree(n+1);

       for(auto x: trust){
           outdegree[x[0]].push_back(x[1]);
       } 
       int ans= -1;
       for(int i = 1; i<=n; i++){
           if(outdegree[i].size()==0){
               ans = i;
               break;
           }
       }
       if(ans==-1)return ans;

       for(int i =1;i<=n;i++){
           if(i!=ans){
               
               bool found = false;

               for(auto x: outdegree[i])
               {
                   if(x==ans){
                       found = true;
                       break;
                   }
               }

               if(!found)return -1;
           }
       }
       return ans;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)


// easy solution

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> indegree(N + 1), outdegree(N + 1);
		for (auto a : trust) {
			++outdegree[a[0]];
			++indegree[a[1]];
		}
		for (int i = 1; i <= N; ++i) {
			if ((indegree[i] == N - 1) && (outdegree[i] == 0)) return i;
		}
		return -1;
    }
};


// Time Complexity - O(n)
// Space Complexity - O(n)
