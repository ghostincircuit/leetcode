#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
                ListNode *ret = NULL;
                ListNode **pp = &ret;

                while (l1 && l2) {
                        if (l1->val < l2->val) {
                                *pp = l1;
                                pp = &(l1->next);
                                l1 = l1->next;
                        } else {
                                *pp = l2;
                                pp = &(l2->next);
                                l2 = l2->next;
                        }
                }
                if (l1) {
                        *pp = l1;
                } else {
                        *pp = l2;
                }
                return ret;
        }
};

void pl(ListNode *t)
{
        while (t) {
                cout << t->val << ' ';
                t = t->next;
        }
        cout << endl;
}

int main()
{
        ListNode *h1 = NULL;
        ListNode *h2 = NULL;

///*
        ListNode **p = &h1;
        for (int i = 0; i < 2; i++) {
                ListNode *t = new ListNode(i+i*i);
                *p = t;
                p = &t->next;
        }
        pl(h1);

///*
        p = &h2;
        for (int i = 0; i < 1; i++) {
                ListNode *t = new ListNode(2*i+i*i+1);
                *p = t;
                p = &t->next;
        }

        pl(h2);
//*/

        Solution s;
        ListNode *h3 = s.mergeTwoLists(h1, h2);
        pl(h3);
        return 0;
}
