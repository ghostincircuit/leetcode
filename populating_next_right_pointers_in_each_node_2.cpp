/**

 * Definition for binary tree with next pointer.

 * struct TreeLinkNode {

 *  int val;

 *  TreeLinkNode *left, *right, *next;

 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

 * };

 */

class Solution {

public:

    int helper(TreeLinkNode *head) {

        

    }

    void connect(TreeLinkNode *root) {

        while (root != NULL) {

            TreeLinkNode *fake = NULL;

            TreeLinkNode **opt = &fake;

            TreeLinkNode *cur = root;

            //int state = 0;

            while(cur != NULL) {

                if (cur->left) {

                    *opt = cur->left;

                    opt = &cur->left->next;

                }

                if (cur->right) {

                    *opt = cur->right;

                    opt = &cur->right->next;

                }

                cur = cur->next;

            }

            *opt = NULL;

            root = fake;

        }

    }

};
