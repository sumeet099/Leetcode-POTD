//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
// logic -> depth first search

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode * root,int mx ,int mn,int &ans ){
        
        if(root->left==NULL && root->right==NULL){
            mx = max(mx,root->val);
            mn = min(mn,root->val);
            ans = max(ans,abs(mx-mn));
            return;
        }

        int tempMax = mx;
        int tempMin = mn;
        
        mx = max(mx,root->val);
        mn = min(mn,root->val);
        
        if(root->left){
            dfs(root->left,mx,mn,ans);
        }

        if(root->right){
            dfs(root->right,mx,mn,ans);
        }

        mx = tempMax;
        mn = tempMin;
    }
    int maxAncestorDiff(TreeNode* root) {
        int mx = root->val;
        int mn = root->val;
        int ans = 0;
        dfs(root,mx,mn,ans);
        return ans;
    }
};

// Time Complexity-> O(N);
// Space Complexity-> O(1);