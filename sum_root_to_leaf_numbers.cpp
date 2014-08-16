#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        stack<int> stk;
        int sum;

        int sumNumbers(TreeNode *root) {
                sum = 0;
                if (root == NULL) {
                        return sum;
                } else {
                        helper(root);
                }
                return sum;
        }
        void helper(TreeNode *root) {
                if (root == NULL)
                        return;
                int prev = 0;
                if (!stk.empty()) {
                        prev = stk.top();
                }

                if (root->left == NULL && root->right == NULL) {
                        sum += (prev*10) + root->val;
                } else {
                        stk.push(root->val + prev*10);
                        helper(root->left);
                        helper(root->right);
                        stk.pop();
                }
        }
};

int main()
{
        TreeNode *h = NULL;
        TreeNode *p = NULL;
        TreeNode *p1 = NULL;

/*
        h = new TreeNode(1);
        p = new TreeNode(3);
        h->left = p;
        p1 = new TreeNode(4);
        h->right = p1;
        p1 = new TreeNode(5);
        p->left = p1;
        p1 = new TreeNode(6);
        p->right = p1;
*/


///*
        h = new TreeNode(1);
//*/


        Solution s;
        cout << s.sumNumbers(h) << endl;

        return 0;
}
