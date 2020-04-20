// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode* dfs(TreeNode *parent, int val) {
        if(parent==nullptr) 
            parent=new TreeNode(val);
        else if(val < parent->val)
            parent->left = dfs(parent->left, val);
        else if( val> parent->val)
            parent->right = dfs(parent->right, val);
        return parent;   
    }

    TreeNode* constructBinTree(vector<int>& preorder) {
        TreeNode *root = dfs(nullptr, preorder[0]);
        for(int i = 1; i<preorder.size() ;i++)
            dfs(root, preorder[i]);
        return root;
    }

    TreeNode* dfsStack1(vector<int>& preorder) {
        TreeNode* root = nullptr;        
        if(preorder.size()==0)
            return root;

        stack<TreeNode*> s;
        root = new TreeNode(preorder[0]);
        s.push(root);

        TreeNode* parent = root;
        for(int i=1;i<preorder.size();i++) {
            int v = preorder[i];
            if(v<parent->val) {
                TreeNode* child = new TreeNode(v);
                parent->left = child;
                parent = child;
                s.push(child);
            } else {
                while(!s.empty()) {
                    if(s.top()->val < v ) {
                        parent = s.top();
                        s.pop();
                    }
                    else
                        break;
                }
                TreeNode* child = new TreeNode(v);
                parent->right = child;
                parent = child;
                s.push(child);                
            }
        }
        return root;
    }
    
    TreeNode* dfsStack2(vector<int>& preorder) {
        TreeNode* root = nullptr;        
        if(preorder.size()==0)
            return root;

        stack<TreeNode*> s;
        root = new TreeNode(preorder[0]);
        s.push(root);

        TreeNode* tmp;
        for(int i=1;i<preorder.size();i++) {
            int v = preorder[i];
            tmp = nullptr;
            while(!s.empty() && s.top()->val < v) {
                tmp = s.top();
                s.pop();
            }
            if(tmp!=nullptr) {
                tmp->right = new TreeNode(v);
                s.push(tmp->right);
            } else {
                s.top()->left = new TreeNode(v);
                s.push(s.top()->left);
            }
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfsStack2(preorder);
    }
};

