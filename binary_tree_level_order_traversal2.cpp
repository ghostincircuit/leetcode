#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
                vector<vector<int> > ret;
                vector<TreeNode *> next, cur;
                if (root == NULL)
                        return ret;
                cur.push_back(root);
                while (cur.size()) {
                        ret.emplace_back();
                        next.clear();
                        for (auto i: cur) {
                                if (i->left)
                                        next.push_back(i->left);
                                if (i->right)
                                        next.push_back(i->right);
                                ret.back().push_back(i->val);
                        }
                        std::swap(cur, next);
                }

                auto b = ret.begin();
                auto e = ret.end();
                e--;
                while (b < e) {
                        b->swap(*e);
                        b++;
                        e--;
                }
                return ret;
        }
};

int main()
{
        TreeNode tree[6];
        for (auto i = 0; i < 6; i++)
                tree[i] = i;
        tree[0].left = tree+1;
        tree[0].right = tree+2;
        tree[1].left = tree+3;
        tree[1].right = tree+4;
        tree[2].left = tree+4;
        tree[2].right = tree+5;
        Solution s;
        auto ret = s.levelOrderBottom(tree);
        for (auto& i: ret) {
                for (auto& j: i)
                        cout << j << " ";
                cout << endl;
        }
        return 0;
}
