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

    int depth;

    int cur = 0;

    Solution() {

        depth = 0;

    }

    void travel(TreeNode *root) {

        if (root == NULL)

            return;

        cur++;

        if (cur > depth)

            depth = cur;

        maxDepth(root->left);

        maxDepth(root->right);

        cur--;

    }

    int maxDepth(TreeNode *root) {

        travel(root);

        return depth;

    }

};
