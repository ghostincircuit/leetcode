struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:        
        typedef vector<int>::iterator vi;
        TreeNode *helper(vi b, vi e) {
                if (b >= e)
                    return NULL;
                vi m = b + (e-b)/2;
                auto p = new TreeNode(*m);
                p->left = helper(b, m);
                p->right = helper(m+1, e);
                return p;
        }
        TreeNode *sortedListToBST(ListNode *head) {
                vector<int> vv;
                while(head) {
                        vv.push_back(head->val);
                        head = head->next;
                }
                return helper(vv.begin(), vv.end());
        }
};
