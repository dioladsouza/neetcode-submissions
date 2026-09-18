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
    int dfs(TreeNode* root, int& max_sum)
    {
        if(root == NULL) return 0;
        int left_sum = max(0, dfs(root->left, max_sum));
        int right_sum = max(0, dfs(root->right, max_sum));
        max_sum = max(max_sum, root->val + left_sum + right_sum);
        return root->val + max(left_sum, right_sum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }
};