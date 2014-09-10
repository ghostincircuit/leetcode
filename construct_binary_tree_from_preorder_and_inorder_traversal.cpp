#include <iostream>
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
        typedef vector<int>::iterator vi;
        TreeNode *rec(vi pre0, vi pre1, vi in0, vi in1) {
                if (pre0 == pre1)
                        return NULL;
                auto rv = *pre0;
                auto i = in0;
                size_t n = 0;
                while (*i != rv) {
                        n++;
                        i++;
                }
                auto root = new TreeNode(rv);
                root->left = rec(pre0+1, pre0+1+n, in0, i);
                root->right = rec(pre0+1+n, pre1, i+1, in1);
                return root;
        }

        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
                vi pre0 = preorder.begin();
                vi pre1 = preorder.end();
                vi in0 = inorder.begin();
                vi in1 = inorder.end();
                return rec(pre0, pre1, in0, in1);
        }
};

void travel(TreeNode *root){
        if (root == NULL)
                return;
        if (root->left)
                travel(root->left);
        cout << root->val << " ";
        if (root->right)
                travel(root->right);
}

int main()
{
        Solution s;
        vector<int> pre, ino;
///*
        pre = {1,2,4,5,3,6,7};
        ino = {4,5,2,1,6,7,3};
//*/
/*
        pre = {1,2,3};
        ino = {2,1,3};
*/
        auto ret = s.buildTree(pre, ino);
        travel(ret);
        return 0;
}
