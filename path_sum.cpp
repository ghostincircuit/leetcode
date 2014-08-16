#include <iostream>
#include <cassert>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        bool helper(TreeNode *root, int sum) {
                assert(root != NULL);
                bool r;
                if (root->left == NULL && root->right == NULL)
                        return sum == root->val;
                if (root->left != NULL) {
                        r = helper(root->left, sum - root->val);
                        if (r == true)
                                return r;
                }

                if (root->right != NULL) {
                        r = helper(root->right, sum - root->val);
                        if (r == true)
                                return r;
                }
                return false;
        }

        bool hasPathSum(TreeNode *root, int sum) {
                if (root == NULL)
                        return false;
                else
                        helper(root, sum);
        }
};


int main()
{
        TreeNode *h, *p1, *p2, *head;
        head = h = new TreeNode(0);
        p1 = new TreeNode(1);
        p2 = new TreeNode(-1);
        h->left = p1;
        h->right = p2;
/*
        h = p1;
        p1 = new TreeNode(1);
        p2 = new TreeNode(2);
        h->left = p1;
        h->right = p2;
*/
        head->right->right = new TreeNode(1);

        Solution s;
        bool r = s.hasPathSum(head, 0);
        cout << r << endl;
        return 0;
}
