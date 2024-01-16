// https://leetcode.com/problems/insert-delete-getrandom-o1/description/
//  logic -> vector stores val at corresponding indices & map is used for checking element is present or not
//  intresting is the remove function just read it and try to understand

class RandomizedSet
{
    vector<int> v;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
    }

    bool search(int val)
    {

        if (mp.find(val) != mp.end())
            return true;
        return false;
    }

    bool insert(int val)
    {

        if (search(val))
            return false;

        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val)
    {

        if (!search(val))
            return false;

        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }

    int getRandom()
    {

        return v[rand() % v.size()];
    }
};

// Time complexity: O(1)
// Space complexity: O(n) +O(n) = O(n)

// my approach - only using set (time & space complexity are equal of previous one)

class RandomizedSet
{
public:
    set<int> st;
    RandomizedSet()
    {
        st.clear();
    }

    bool insert(int val)
    {
        if (st.count(val) == 0)
        {
            st.insert(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val)
    {
        auto it = st.find(val);
        if (it != st.end())
        {
            st.erase(it);
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom()
    {
        return *next(st.begin(), rand() % st.size());
    }
};

// Time complexity: O(1)
// Space complexity: O(n)