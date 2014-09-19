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

    bool isSymmetric(TreeNode *root) {

        if (!root)

            return true;

        list<TreeNode *> left, right, newl, newr;

        left.push_back(root->left);

        right.push_back(root->right);



        while (left.size() == right.size()) {

            if (left.size() == 0)

                return true;



            auto li = left.begin();

            auto ri = right.end();

            ri--;

            while (li != left.end()) {

                if ((*li == 0 && *ri != 0) ||

                    (*li != 0 && *ri == 0)) {

                    return false;

                    

                } else if (*li == 0 && *ri == 0) {

                } else if ((*li)->val != (*ri)->val)

                    return false;

                else {

                    newl.push_back((*li)->left);

                    newl.push_back((*li)->right);

                    newr.push_front((*ri)->right);

                    newr.push_front((*ri)->left);

                }

                li++;

                ri--;

            }

            newl.swap(left);

            newr.swap(right);

            newl.clear();

            newr.clear();

        }

        return false;

    }
};
