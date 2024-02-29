//https://leetcode.com/problems/even-odd-tree/description/

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
    bool isEvenOddTree(TreeNode* root) {
    if(root==NULL)return true;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int sz = q.size();
        vector<int> t;
        bool odd = false;
        bool even = false;
        while(sz--){
            if(q.front()->val % 2)odd = true;
            else even = true;
            t.push_back(q.front()->val);
            if(q.front()->left)q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);
            q.pop();
        }
        if((level % 2==1 && odd==true) ||(level%2==0 && even==true))return false;
        if(level%2){
            for(int i = 0; i<t.size()-1; i++)if(t[i+1] >= t[i])return false;
        }else{
            for(int i = 0; i<t.size()-1; i++)if(t[i+1] <= t[i])return false;
        }
        level++;
    }

    return true;
    }
};

// Time Complexity - O(N);
// Space Complexity - O(N); (it can be done in O(1) space complexity but for understanding this is much better )


