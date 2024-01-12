// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
// logic - store vowels in map which is constant space and iterate for half add+=1 when encounter vowel and subtract for other half for same
// we know if count is zero it means equal no of vowels else not

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int ct = 0;
        int n = s.size();
        map<char, int> m = {{'a', 1}, {'A', 1}, {'e', 1}, {'E', 1}, {'i', 1}, {'I', 1}, {'o', 1}, {'O', 1}, {'u', 1}, {'U', 1}};
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
            {
                if (m.count(s[i]))
                    ct++;
            }
            else
            {
                if (m.count(s[i]))
                    ct--;
            }
        }

        return (ct == 0);
    }
};

// Time Complexity -> O(n)
// Space Complexity -> O(1)
