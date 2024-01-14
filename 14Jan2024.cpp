// https://leetcode.com/problems/determine-if-two-strings-are-close/description/
// logic - simple just check all freq after sorting for both are equal and alphabets used is same for both then return true else false

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        vector<int> a(26, 0), b(26, 0);
        for (auto x : word1)
            a[x - 'a']++;
        for (auto x : word2)
            b[x - 'a']++;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        set<char> set1(word1.begin(), word1.end());
        set<char> set2(word2.begin(), word2.end());

        return (set1 == set2 && a == b);
    }
};

// Time Complexity -> O(N log(N))
// Time Complexity -> O(26) (noting but O(1) ie. constant space)