//https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int find_height(int &ans,TreeNode*root){
        if(root==NULL)return 0;

        int left = find_height(ans,root->left);
        int right = find_height(ans,root->right);

        // here is the important step for finding diameter
        ans = max(ans,left+right);
       
        return 1+ max(left,right); 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //to find diameter we have to find left and right subtree height at each node
        int diameter = 0;
        int height = find_height(diameter,root);
        return diameter; 
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)
