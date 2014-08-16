#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

        pair<ListNode *, ListNode *> helper(ListNode *head) {
                pair<ListNode *, ListNode *> ret;
                int m = head->val;
                ListNode *left = NULL;
                ListNode *right = NULL;
                ListNode *mid = head;
                ListNode *mtail = head;
                ListNode *p;
                p = head->next;

                if (p == NULL) {
                        return pair<ListNode *, ListNode *>(mid, mid);
                }

                while (p != NULL) {
                        ListNode *tp = p;
                        p = p->next;

                        if (tp->val == m) {
                                tp->next = mid;
                                mid = tp;
                        } else if (tp->val < m) {
                                tp->next = left;
                                left = tp;
                        } else {
                                assert(tp->val > m);
                                tp->next = right;
                                right = tp;
                        }
                }
                pair<ListNode *, ListNode *> rl, rr;
                int use_rl, use_rr;
                if (left != NULL) {
                        rl = helper(left);
                        use_rl = 1;
                } else
                        use_rl = 0;

                if (right != NULL) {
                        rr = helper(right);
                        use_rr = 1;
                } else
                        use_rr = 0;

                if (use_rl) {
                        rl.second->next = mid;
                        mtail->next = use_rr ? rr.first : NULL;
                        return pair<ListNode *, ListNode *>(rl.first, (use_rr ? rr.second : mtail));
                } else {
                        mtail->next = use_rr ? rr.first : NULL;
                        return pair<ListNode *, ListNode *>(mid, (use_rr ? rr.second : mtail));
                }
        }

        ListNode *sortList(ListNode *head) {
                if (head == NULL)
                        return NULL;
                pair<ListNode *, ListNode *> r = helper(head);
                return r.first;
        }
};

#define N 2

int main()
{
        ListNode *head = NULL;
        ListNode *p;

        int a[] = {2,3,2,34,43,3,2,2,5,3,3,2,1};
        for (int i = 0; i < N; i++) {
                p = new ListNode(a[i]);
                p->next = head;
                head = p;
        }

        for (ListNode *p1 = head; p1 != NULL; p1=p1->next) {
                cout << p1->val << ' ';
        }
        cout << endl;

        Solution s;
        head = s.sortList(head);

        for (ListNode *p1 = head; p1 != NULL; p1=p1->next) {
                cout << p1->val << ' ';
        }
        cout << endl;

        return 0;
}
