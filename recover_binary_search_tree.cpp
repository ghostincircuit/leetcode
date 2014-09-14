#include <vector>
#include <cstdio>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<pair<TreeNode *, TreeNode *> > fifo;
        int cnt;
        TreeNode *last;
        void travel(TreeNode *r) {
                if (r == NULL)
                        return;
                if (r->left)
                        travel(r->left);
                if (last->val > r->val) {
                        fifo.push_back(make_pair(last, r));
                }
                last = r;
                if (last->right)
                        travel(r->right);
        }

        void recoverTree(TreeNode *root) {
                auto tmp = new TreeNode(-0x7fffffff);
                last = tmp;
                travel(root);
                if (fifo.size() == 1) {
                        auto i = fifo[0].first;
                        auto ii = fifo[0].second;
                        int t = i->val;
                        i->val = ii->val;
                        ii->val = t;
                } else {
                        auto i = fifo[0].first;
                        auto ii = fifo[1].second;
                        int t = i->val;
                        i->val = ii->val;
                        ii->val = t;
                }
                delete tmp;
        }
};

int main()
{
        Solution s;
        TreeNode *p0 = new TreeNode(1);
        TreeNode *p1 = new TreeNode(2);
        TreeNode *p2 = new TreeNode(3);
/*
        p0->left = p1;
        p0->right = p2;
*/
        p0->left = p1;
        p0->right = p2;
        s.recoverTree(p0);
        return 0;
}
