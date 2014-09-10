struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        typedef vector<int>::iterator vii;
        TreeNode *helper(vii b, vii e) {
                auto sz = e - b;
                if (sz == 0)
                        return NULL;
                else if (sz == 1) {
                        return new TreeNode(*b);
                } else {
                        auto mid = b + sz/2;
                        auto midp = new TreeNode(*mid);
                        midp->left = helper(b, mid);
                        midp->right = helper(mid+1, e);
                        return midp;
                }
        }
        TreeNode *sortedArrayToBST(vector<int> &num) {
                return helper(num.begin(), num.end());
        }
};
