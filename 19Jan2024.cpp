// https://leetcode.com/problems/minimum-falling-path-sum/description/

// tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int diagonallyLeft = matrix[i][j] + (j + 1 < m ? dp[i - 1][j + 1] : 1e6);
                int below = matrix[i][j] + dp[i - 1][j];
                int diagonallyRight = matrix[i][j] + (j >= 1 ? dp[i - 1][j - 1] : 1e6);

                dp[i][j] = min({diagonallyLeft, below, diagonallyRight});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// Time complexity -> O(n*m)
// Space complexity -> O(n*m)

// tabulation with space optimization

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0), cur(m, 0);

        for (int i = 0; i < m; i++)
            prev[i] = matrix[0][i];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int diagonallyLeft = matrix[i][j] + (j + 1 < m ? prev[j + 1] : 1e6);
                int below = matrix[i][j] + prev[j];
                int diagonallyRight = matrix[i][j] + (j >= 1 ? prev[j - 1] : 1e6);

                cur[j] = min({diagonallyLeft, below, diagonallyRight});
            }
            prev = cur;
        }

        return *min_element(prev.begin(), prev.end());
    }
};

// Time complexity -> O(n*m)
// Space complexity -> O(m)