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
    TreeNode* buildSubTree(vector<int>& preorder, int preStart, int preEnd,
            vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp)
    {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int root_idx = mpp[root->val];
        int num_left_nodes = root_idx - inStart;
        
        root->left = buildSubTree(preorder, preStart + 1, preStart + num_left_nodes,
                    inorder, inStart, root_idx - 1, mpp);
        root->right = buildSubTree(preorder, preStart + num_left_nodes + 1, preEnd,
                    inorder, root_idx + 1, inEnd, mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++)
            mpp[inorder[i]] = i;
        TreeNode* root = buildSubTree(preorder, 0, preorder.size() - 1, 
                        inorder, 0, inorder.size() - 1, mpp);
        return root;
    }
};