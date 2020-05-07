//https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool bfs(TreeNode* node, int x, int y) {
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(node,-1));
        int par_x = -1;
        int par_y = -1;
        while(!q.empty()) {
            int n=q.size();
            for(int i=0;i<n;i++) {
                auto p = q.front();
                q.pop();
                TreeNode* cur = p.first;
                if(cur->val==x) par_x = p.second;
                if(cur->val==y) par_y = p.second;
                if(cur->left!=nullptr)  q.push(make_pair(cur->left, cur->val));
                if(cur->right!=nullptr) q.push(make_pair(cur->right, cur->val));
            }
            if(par_x!=-1 && par_y!=-1)
                return par_x!=par_y;
            else if(par_x!=-1 || par_y!=-1)
                return false;
        }
       return false;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        return bfs(root,x,y);
    }
};
