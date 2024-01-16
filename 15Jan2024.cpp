// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
//  logic -> simple just check from total elments which are satisfying the condition mentioned in question

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> lost;
        set<int> total;
        for (auto c : matches)
        {
            total.insert(c[0]);
            total.insert(c[1]);
            lost[c[1]]++;
        }
        vector<vector<int>> ans(2);
        for (auto x : total)
        {
            if (lost.count(x) == 0)
            {
                ans[0].push_back(x);
            }
            else if (lost[x] == 1)
            {
                ans[1].push_back(x);
            }
        }
        return ans;
    }
};

// Time complexity->o(N log N)
// Space complexity->o(N )
