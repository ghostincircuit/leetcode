#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        stack<TreeNode *> stk;
        void flatten(TreeNode *root) {
                if (root == NULL)
                        return;
                stk.push(root);
                TreeNode *fake = NULL;
                TreeNode **last = &fake;
                while (!stk.empty()) {
                        auto t = stk.top();stk.pop();
                        *last = t;
                        last = &t->right;
                        if (t->right)
                                stk.push(t->right);
                        if (t->left)
                                stk.push(t->left);
                        t->left = NULL;
                }
                *last = NULL;
        }
};
