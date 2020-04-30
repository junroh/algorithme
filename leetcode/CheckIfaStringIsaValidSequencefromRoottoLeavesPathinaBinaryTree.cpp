//Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/
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
    bool dfs(TreeNode* node, vector<int>& arr, int idx) {
        if(node==nullptr || idx==arr.size())
            return false;

        if(node->left == nullptr && node->right == nullptr &&
            idx == arr.size()-1 && node->val == arr[idx])
             return true;

        return node->val == arr[idx] &&
            (dfs(node->left, arr, idx+1) || dfs(node->right, arr, idx+1));
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
};
