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
        int postidx;
        vector<int> *post;
        TreeNode *rev(vector<int>::iterator inb, vector<int>::iterator ine) {
                if (inb == ine)
                        return NULL;

                int m = (*post)[postidx--];
                TreeNode *root = new TreeNode(m);

                vector<int>::iterator i = inb;
                for (; i != ine; i++) {
                        if (*i == m)
                                break;
                }

                root->right = rev(i+1, ine);
                root->left = rev(inb, i);
                return root;
        }

        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

                if (inorder.size() == 0)
                        return NULL;
                post = &postorder;
                postidx = postorder.size()-1;

                TreeNode *root = rev(inorder.begin(), inorder.end());
                return root;
        }
};


int main()
{
//        int ina[] = {2,1,3};
//        int posta[] = {2,3,1};

        int ina[] = {4,2,5,1,6,3};
        int posta[] = {4,5,2,6,3,1};

        vector<int> inv(ina, ina + sizeof(ina)/sizeof(ina[0]));
        vector<int> postv(posta, posta + sizeof(posta)/sizeof(posta[0]));
        Solution s;
        TreeNode *ret = s.buildTree(inv, postv);
        return 0;
}
