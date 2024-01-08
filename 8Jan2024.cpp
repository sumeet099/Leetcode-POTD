// https://leetcode.com/problems/range-sum-of-bst/description/
//logic -> traversing tree and getting required answer

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
    void inorder(TreeNode* ptrToNode,int low,int high,int &ans){
        if(ptrToNode==NULL){
            return;
        }
        else{
            inorder(ptrToNode->left,low,high,ans);
            int nodeData = ptrToNode->val;
            if(nodeData<=high && nodeData>=low){
                ans+=nodeData;
            }
            inorder(ptrToNode->right,low,high,ans);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        inorder(root,low,high,ans);
        return ans;
    }
};

//Time Complexity-> O(N) - where N is total No. of nodes in tree
// Space Complexity -> O(1)