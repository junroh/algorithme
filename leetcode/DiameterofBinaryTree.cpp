//https://leetcode.com/problems/diameter-of-binary-tree/
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
    int dia;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dia=1;
        dfs(root);
        return dia-1;
    }
    
    int dfs(TreeNode* node) {
        if(node==nullptr) return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        dia = max(dia, L+R+1);
        return max(L,R)+1;
    }
};
