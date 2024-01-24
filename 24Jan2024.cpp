//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
//logic - depth first seach 


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
    void dfs(TreeNode* root,vector<int>&v,int &ans){
        if(root==NULL)return;
        if(root!=NULL && root->left==NULL && root->right==NULL ){
            v[root->val]++;
            int odd =0;
            int even = 0;
            for(int i = 0; i<10; i++){
                if(v[i] % 2)odd++;
                else even+=v[i];
            }
            if(odd <=1)ans++;
            v[root->val]--;
            return;
        }
        
        v[root->val]++;

        dfs(root->left,v,ans);
        
        dfs(root->right,v,ans);

        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        int ans = 0;
        dfs(root,v,ans);
        return ans;
    }
};

//Time Complexity - O(N);
//Space Complexity - O(1);
