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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int depth)
    {
        if(root == NULL) return;
        if(depth == ans.size())
            ans.push_back({});
        ans[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //recursive approach - uses dfs
        dfs(root, 0);
        return ans;
    }
};
