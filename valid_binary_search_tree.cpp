/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool helper(TreeNode *root, long long l, long long r) {
        if (root == NULL)    
            return true;
        if (root->val <= l)
            return false;
        if (r <= root->val)
            return false;
        return helper(root->left, l, root->val) && helper(root->right, root->val, r);
    }
    
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;
        long long l, r;
        r = 0x100000000;
        l = -0x100000000;
        return helper(root, l, r);
    }
};
