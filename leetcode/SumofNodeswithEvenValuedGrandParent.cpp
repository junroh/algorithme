// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
    int sum=0;
    void dfs(TreeNode* node, TreeNode* parent, TreeNode* grandParent) {
        if(node==nullptr)   return;
        if(grandParent!=nullptr && (grandParent->val&0x01)==0)
            sum += node->val;
        dfs(node->left, node, parent);
        dfs(node->right, node, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,nullptr,nullptr);
        return sum;
    }
};
