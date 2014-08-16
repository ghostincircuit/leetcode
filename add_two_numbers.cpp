#include <iostream>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
                int s = 0;
                int c = 0;
                ListNode *ret = NULL;
                ListNode **pp = &ret;

                while (l1 && l2) {
                        s = l1->val + l2->val + c;
                        if (s > 9) {
                                c = 1;
                                s = s - 10;
                        } else {
                                c = 0;
                        }
                        ListNode *t = new ListNode(s);
                        *pp = t;
                        pp = &t->next;
                        l1 = l1->next;
                        l2 = l2->next;
                }

                ListNode *p;
                if (l1)
                        p = l1;
                else if (l2)
                        p = l2;
                else
                        p = NULL;
                while (p || c) {
                        int pv = 0;
                        if (p != NULL)
                                pv = p->val;
                        s = pv + c;
                        if (s > 9) {
                                c = 1;
                                s = s - 10;
                        } else {
                                c = 0;
                        }
                        ListNode *t = new ListNode(s);
                        *pp = t;
                        pp = &t->next;
                        if (p)
                                p = p->next;
                }
                return ret;
        }
};

int main()
{
        ListNode *p0 = new ListNode(1);
        ListNode *p1 = new ListNode(9);

        ListNode *p3 = new ListNode(2);
        p0->next = p3;


        Solution s;
        ListNode *p2 = s.addTwoNumbers(p1, p0);
        for (; p2 != NULL;p2=p2->next) {
                cout << p2->val << ' ';
        }
        cout << endl;
        return 0;
}
