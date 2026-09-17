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
private: 
    int dfs(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left_ht = dfs(root->left);
        if(left_ht == -1) return -1;
        int right_ht = dfs(root->right);
        if(right_ht == -1) return -1;

        if(abs(left_ht - right_ht) > 1) return -1;
        return 1 + max(left_ht, right_ht);
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
