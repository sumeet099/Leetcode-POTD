//https://leetcode.com/problems/leaf-similar-trees/description/

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

    void storeLeafNodes(vector<int> &v,TreeNode*root){
        if(root==NULL){
            return;
        }
        else{
            storeLeafNodes(v,root->left);
            if(root!=NULL && root->left==NULL && root->right==NULL ){
                v.push_back(root->val);
            }
            storeLeafNodes(v,root->right);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1,leaf2;
        storeLeafNodes(leaf1,root1);
        storeLeafNodes(leaf2,root2);
        if(leaf1.size()!=leaf2.size())return false;

        for(int i= 0; i<leaf1.size(); i++){
            if(leaf1[i]!=leaf2[i]){
                return false;
            }
        }

        return true;
    }
};


// Time Complexity-> O(N);
// Space Complexity-> O(N);