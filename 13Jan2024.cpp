// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
//  logic -> simply  store count of each alphabet of string s and subract count of each alphabet of string t correspondigly
//   operations is just half of sum of all frequencies we stored
class Solution
{
public:
    int minSteps(string s, string t)
    {
        int v[26] = {0};
        for (char c : s)
        {
            v[c - 'a']++;
        }
        for (char c : t)
        {
            v[c - 'a']--;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            ans += abs(v[i]);
        }
        return ans >> 1;
    }
};

// Time Complexity -> O(N)
// Time Complexity -> O(26) (noting but O(1) ie. constant space)