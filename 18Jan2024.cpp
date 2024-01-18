// https://leetcode.com/problems/climbing-stairs/description/

// memoization

class Solution
{
public:
    int f(int i, vector<int> &dp)
    {
        if (i <= 1)
        {
            return 1;
        }
        if (dp[i] != -1)
            return dp[i];
        int oneStep = f(i - 1, dp);
        int twoStep = f(i - 2, dp);
        return dp[i] = oneStep + twoStep;
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

// Time Complexity - O(n)
//  Space Complexity - O(n)(recursion stack space)+ O(n) (arbitary space)

// tabulation

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};

// Time Complexity - O(n)
//  Space Complexity - O(n) (arbitary space)  (here no recursion stack space)

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev = 1;
        int cur = 1;
        for (int i = 2; i <= n; i++)
        {
            int temp = cur + prev;
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};

// tabulation with space optimisation
// Time Complexity - O(n)
//  Space Complexity - O(1);