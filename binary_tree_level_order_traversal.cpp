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



    vector<vector<int> > levelOrder(TreeNode *root) {

        vector<vector<int> > ret;

        vector<TreeNode *> cur, next;

        if (root)

            cur.push_back(root);

        while(cur.size()) {

            next.clear();

            ret.emplace_back();

            auto& ref = ret.back();

            for (auto& i: cur) {

                ref.push_back(i->val);

                if (i->left)

                    next.push_back(i->left);

                if (i->right)

                    next.push_back(i->right);

            }

            next.swap(cur);

        }

        return ret;

    }

};
