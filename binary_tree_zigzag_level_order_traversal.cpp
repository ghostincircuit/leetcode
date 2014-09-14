#include <cstdio>
#include <vector>
#include <list>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
                vector<vector<int> > ret;
                list<TreeNode *> cur, prev;
                if (root == NULL)
                        return ret;
                prev.push_back(root);
                bool dir = true;
                while (prev.size()) {
                        ret.push_back(vector<int>());
                        if (dir) {
                                for (auto i = prev.begin(); i != prev.end(); i++)
                                        ret.back().push_back((*i)->val);
                        } else {
                                auto i = prev.end();
                                i--;
                                for (;i != prev.begin(); i--)
                                        ret.back().push_back((*i)->val);
                                ret.back().push_back((*i)->val);
                        }
                        dir = !dir;
                        cur = list<TreeNode *>();
                        for (auto& i: prev) {
                                if (i->left)
                                        cur.push_back(i->left);
                                if (i->right)
                                        cur.push_back(i->right);
                        }
                        prev = cur;
                }
                return ret;
        }
};

int main()
{
        Solution s;
        s.zigzagLevelOrder(NULL);
        return 0;
}
