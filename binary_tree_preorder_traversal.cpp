#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<int> preorderTraversal(TreeNode *root) {
                vector<int> ret;
                if (root == NULL)
                        return ret;
                stack<TreeNode *> stk;
                stk.push(root);

                while (!stk.empty()) {
                        TreeNode *p = stk.top();stk.pop();
                        ret.push_back(p->val);
                        if (p->right)
                                stk.push(p->right);
                        if (p->left)
                                stk.push(p->left);
                }
                return ret;
        }
};

int main()
{
        TreeNode *root = NULL;
        vector<int> r;
        Solution s;

        root = new TreeNode(0);
        TreeNode *p;
        root->left = new TreeNode(1);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);

        r = s.preorderTraversal(root);


        for (vector<int>::iterator vi = r.begin();
             vi != r.end();
             vi++)
                cout << *vi << ' ';
        cout << endl;
        return 0;
}
