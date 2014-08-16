#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
        ListNode *insertionSortList(ListNode *head) {
                if (head == NULL)
                        return NULL;

                ListNode *rem = head->next;
                head->next = NULL;
                while (rem != NULL) {
                        ListNode *target = rem;
                        rem = rem->next;
                        int v = target->val;
                        ListNode **pp = &head;
                        while (*pp != NULL) {
                                if ((*pp)->val > v)
                                        break;
                                pp = &(*pp)->next;
                        }

                        target->next = (*pp);
                        *pp = target;
                }
                return head;
        }
};

int main()
{
        ListNode *h = NULL;
        ListNode *tr;

        h = new ListNode(3);
        h->next = new ListNode(2);

/*
        for (int i = 0; i < 8; i++) {
                ListNode *p = new ListNode(i*i-3*i);
                p->next = h;
                h = p;
        }

*/
        tr = h;
        while (tr) {
                cout << tr->val << ' ';
                tr = tr->next;
        }
        cout << endl;

        Solution s;
        h = s.insertionSortList(h);

        tr = h;
        while (tr) {
                cout << tr->val << ' ';
                tr = tr->next;
        }
        cout << endl;
        
        return 0;
}
