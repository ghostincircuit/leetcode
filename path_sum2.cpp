struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<TreeNode *> cur;
        int cs;
        int sum;
        vector<vector<int> > ps;
        void helper(TreeNode *r) {
                if (r->left == NULL && r->right ==  NULL) {
                        if (r->val + cs == sum) {
                                vector<int> tmp;
                                for (auto i = cur.begin(); i != cur.end(); i++)
                                        tmp.push_back((*i).val);
                                tmp.push_back(r->val);
                                ps.emplace_back(tmp);
                        }
                } else {
                        cs += r->val;
                        cur.push_back(r);
                        if (r->left) {
                                helper(r->left);
                        }
                        if (r->right) {
                                helper(r->right);
                        }
                        cs -= r->val;
                        cur.pop_back();
                }
        }
        vector<vector<int> > pathSum(TreeNode *root, int s) {
                if (root == NULL)
                        return ps;
                sum = s;
                cs = 0;
                helper(root);
                return ps;
        }
};
