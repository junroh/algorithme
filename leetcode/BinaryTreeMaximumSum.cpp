// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxSum;
public:
    int dfs(TreeNode* node) {
        if(node==nullptr)   
            return 0;
        int lsum = dfs(node->left);
        int rsum = dfs(node->right);
        // max sum of left of right child include this node
        int sum = max(node->val, node->val + max(lsum,rsum));
        // max sum including both left and right
        maxSum = max(maxSum, max(sum, node->val + lsum + rsum));
        return sum;
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};
