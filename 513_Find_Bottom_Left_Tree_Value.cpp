https://leetcode.com/problems/find-bottom-left-tree-value/description/

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
    int findBottomLeftValue(TreeNode* root) {
      if(root==NULL)return -1;
      
      int ans = 0;
      
      queue<TreeNode*> q;
      q.push(root);
      

      while(!q.empty()){
          int sz = q.size();
          bool notVisited = true;
          while(sz--){
              if(notVisited){
                  ans = q.front()->val;
                  notVisited = false;
              }
              if(q.front()->left)q.push(q.front()->left);
              if(q.front()->right)q.push(q.front()->right);
              q.pop();
          }
      }

      return ans;
    }
};
 // Time Complexity - O(N);
 // Space Complexity - O(1);
