// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// logic -> //  breadth first search 
            //  but intially storing parents pointers for the purpose of bfs


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
    void inorder(TreeNode*p ,TreeNode* &target, int start){
        if(p==NULL){
            return ;
        }
        else{
            inorder(p->left,target,start);
             if(p->val==start){
                 target = p;
             }
            inorder(p->right,target,start);
        }
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> parent;
        markparent(parent,root);
        
        TreeNode *target;
        inorder(root,target,start);

        map<TreeNode*,bool> visited;
        int dist  = 0;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        while(!q.empty()){

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

        return --dist;

    }
};


// Time Complexity-> O(N log (N));
// Space Complexity-> O(N);
