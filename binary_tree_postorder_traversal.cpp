#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<int> postorderTraversal(TreeNode *root) {
                vector<int> stki;
                stack<TreeNode *> stkp;
                stkp.push(root);

                while (!stkp.empty()) {
                        TreeNode *t = stkp.top();stkp.pop();
                        if (t == NULL)
                                continue;

                        stki.push_back(t->val);
                        if (t->left)
                                stkp.push(t->left);
                        if (t->right)
                                stkp.push(t->right);
                }
                reverse(stki.begin(), stki.end());
                return stki;
        }
};

int main()
{
        TreeNode *root = new TreeNode(0);
        TreeNode *p1 = new TreeNode(1);
        TreeNode *p2 = new TreeNode(2);
        TreeNode *p3 = new TreeNode(3);
        TreeNode *p4 = new TreeNode(4);
        TreeNode *p5 = new TreeNode(5);
        TreeNode *p6 = new TreeNode(6);

        root = NULL;
/*
        root->left = p1;
        root->right = p2;

        p1->left = p3;
        p1->right = p4;

        p2->left = p5;
        p2->right = p6;
*/

        Solution s;
        vector<int> ret = s.postorderTraversal(root);

        for (int i = 0; i < ret.size(); i++)
                cout << ret[i] << ' ';
        cout << endl;
        return 0;
}
