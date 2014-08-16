#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
        TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
        void connect(TreeLinkNode *root) {
                int sz = 1;
                queue<TreeLinkNode *> q;
                TreeLinkNode **pp;
                if (root == NULL)
                        return;
                q.push(root);
                while (!q.empty()) {
                        for (int i = 0; i < sz; i++) {
                                TreeLinkNode *t = q.front();q.pop();
                                if (i != 0) {//last one
                                        *pp = t;
                                }
                                pp = &t->next;
                                if (t->left != NULL) {
                                        assert(t->right != NULL);
                                        q.push(t->left);
                                        q.push(t->right);
                                }
                        }
                        sz <<= 1;
                }
        }
};

int main()
{
        TreeLinkNode *head, *p1, *p2, *p3;
        head = new TreeLinkNode(0);
        p1 = head->left = new TreeLinkNode(1);
        p2 = head->right = new TreeLinkNode(2);
        p1->left = new TreeLinkNode(3);
        p1->right = new TreeLinkNode(4);
        p2->left = new TreeLinkNode(5);
        p2->right = new TreeLinkNode(6);

        Solution s;
        s.connect(head);

        assert(head->next == NULL);
        assert(p1->val == 1);
        assert(p1->next->val == 2);
        assert(p1->next->next == NULL);
        assert(p1->left->val == 3);
        assert(p1->left->next->val == 4);
        assert(p1->left->next->next->val == 5);
        assert(p1->left->next->next->next->val == 6);
        assert(p1->left->next->next->next->next == NULL);
        return 0;
}
