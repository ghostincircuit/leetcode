#include <vector>
#include <cstdio>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<TreeNode *> helper(int l, int r) {
                vector<TreeNode *> ret, retl, retr;
                if (l == r) {
                        ret.push_back(NULL);
                        return ret;
                }
                for (int i = l; i < r; i++) {
                        retl = helper(l, i);
                        retr = helper(i+1, r);
                        for (auto& j: retl)
                                for (auto& k: retr) {
                                        auto p = new TreeNode(i);
                                        p->left = j;
                                        p->right = k;
                                        ret.push_back(p);
                                }
                }
                return ret;
        }
        vector<TreeNode *> generateTrees(int n) {
                vector<TreeNode *> ret;
                if (n == 0) {
                        ret = vector<TreeNode *>();
                        ret.push_back(NULL);
                }
                else
                        ret = helper(1, n+1);
                return ret;
        }
};

int main()
{
        Solution s;
        s.generateTrees(10);
        return 0;
}
