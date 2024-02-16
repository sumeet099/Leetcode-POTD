// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
//  logic - used elements having minimum frequency

//-----------------------------------------------------------------------------------------
// 1) Using Sorting Algorithm 

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> m;

        for (auto x : arr)
            m[x]++;

        vector<pair<int, int>> v;

        int ans = 0;
        for (auto x : m)
        {
            v.push_back({x.second, x.first});
            ans += 1;
        }

        sort(v.begin(), v.end());

        for (auto x : v)
        {
            if (k >= x.first)
            {
                k -= x.first;
                ans--;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};

// Time Complexity - O(n log(n))
// Space Complexity - O(n)


//-----------------------------------------------------------------------------------------

// 2) using MinHeap (priority_queue)

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {

        unordered_map<int, int> m;

        for (auto x : arr)
            m[x]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto x : m)
        {
            minHeap.push(x.second);
        }

        int curRemoved = 0;

        while (!minHeap.empty())
        {

            curRemoved += minHeap.top();

            if (curRemoved > k)
            {
                return minHeap.size();
            }
            else
            {
                minHeap.pop();
            }
        }

        return 0;
    }
};

// Time Complexity - O(n log(n))
// Space Complexity - O(n)


//-----------------------------------------------------------------------------------------

// 3) Optimized Solution using Count Sorting Algorithms ( used logic is that count Frequency of Frequency)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int> m;

        for(auto x: arr)m[x]++;

        int n = arr.size();

        vector<int> ct(n+1,0);

        for(auto x: m)ct[x.second]++;

        int remainingUniqueElements = m.size();

        for(int freq= 1; freq<=n ;freq++){

             int numElementsRemove = min(k/freq,ct[freq]);

             k-=numElementsRemove*freq;

            remainingUniqueElements-=numElementsRemove;

            if(k<=freq)return remainingUniqueElements;
             
        }
        return remainingUniqueElements;

    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
