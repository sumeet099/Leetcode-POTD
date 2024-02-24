//https://leetcode.com/problems/find-all-people-with-secret/description/
// logic - breadth first search on same time interval pairs who sharing secret at any time t 

#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> can(n);  // Vector to represent whether a person can know the secret
        can[0] = can[firstPerson] = true;  // Person 0 and the person specified by firstPerson initially know the secret

        map<int, vector<pair<int, int>>> mp;  // Map to store meetings grouped by time

        // Group meetings based on time
        for (auto& meeting : meetings) 
            mp[meeting[2]].push_back({meeting[0], meeting[1]}); 

        // Iterate through meetings
        for (auto& [k, v] : mp) {
            unordered_map<int, vector<int>> graph;  // Adjacency list to represent the graph of people in the meeting
            unordered_set<int> st;  // Set to store people who currently know the secret

            // Build the graph and set based on the people in the meeting
            for (auto& [x, y] : v) {
                graph[x].push_back(y); 
                graph[y].push_back(x); 
                if (can[x]) st.insert(x); 
                if (can[y]) st.insert(y); 
            }

            queue<int> q; 

            // Initialize the queue with people who currently know the secret
            for (auto& x : st) q.push(x); 
            
            // Perform BFS to find additional people who can know the secret
            while (q.size()) {
                auto x = q.front(); q.pop(); 
                for (auto& y : graph[x]) 
                    if (!can[y]) {
                        can[y] = true; 
                        q.push(y); 
                    }
            }
        }
        
        vector<int> ans; 

        // Collect the indices of people who know the secret
        for (int i = 0; i < n; ++i) 
            if (can[i]) ans.push_back(i); 

        return ans;  // Return the final list of people who know the secret
    }
};

// Time Complexity -  O(m + V + E) where where m is the number of meetings,where V is the number of vertices (people) and E is the number of edges (connections/meetings).
//Space Complexity - O(V + E)

// for better understanding refer solution below
// https://leetcode.com/problems/find-all-people-with-secret/solutions/4776976/well-explained-c-code/
