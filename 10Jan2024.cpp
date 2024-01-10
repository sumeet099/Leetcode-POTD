// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// logic -> //  breadth first search 
            //  but intially storing parents pointers for the purpose of bfs

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:

    void markparent(map<TreeNode*,TreeNode*> &parent,TreeNode* root){
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode * Node = q.front();
            q.pop();

            if(Node->left){
                q.push(Node->left);
            parent[Node->left] = Node; 
            }
            if(Node->right){
                q.push(Node->right);
            parent[Node->right] = Node; 
            }

        }

        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        markparent(parent,root);

        map<TreeNode*,bool> visited;
        int dist  =0;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        while(!q.empty()){
            if(dist==k)break;

            int sz = q.size();
            dist++;
            while(sz--){
                TreeNode * Node = q.front();
                q.pop();

                if(Node->left && !visited[Node->left]){
                    q.push(Node->left);
                    visited[Node->left]= true;
                }
                if(Node->right && !visited[Node->right]){
                    q.push(Node->right);
                    visited[Node->right]=true;
                }
                if(parent[Node] && !visited[parent[Node]])
                {
                    q.push(parent[Node]);
                    visited[parent[Node]]= true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }

};


// Time Complexity-> O(N log (N));
// Space Complexity-> O(N);