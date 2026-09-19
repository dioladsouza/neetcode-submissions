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
    int count = 0;
    int dfs(TreeNode* root, int max_val)
    {
        if(root == NULL) return 0;

        if(max_val <= root->val)
        {
            count++;
            max_val = max(max_val, root->val);
        }
        dfs(root->left, max_val);
        dfs(root->right, max_val);
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
