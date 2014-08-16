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
        bool helper(ListNode **phead, int n) {
                ListNode *head = *phead;
                if (head == NULL)
                        return false;
                assert(n > 0);
                ListNode *p = head->next;
                n--;
                while (p != NULL && n) {
                        n--;
                        if (p == head)
                                return true;
                        else
                                p = p->next;
                }
                if (p == NULL) {
                        *phead = p;
                        return false;
                }

                if (head == p)
                        return true;
                else {
                        *phead = p;
                        return false;
                }
        }

        bool hasCycle(ListNode *head) {
                for (int i = 1; i < 30; i++) {
                        if (helper(&head, 1<<i) == true)
                                return true;
                        else if (head == NULL)
                                return false;
                }
                return false;
        }
};

int main()
{
        ListNode *h = new ListNode(3);

/*
        ListNode *p = new ListNode(2);
        ListNode *p2;
        h->next = p;
        p2 = p;

        p = new ListNode(0);
        p2->next = p;
        p2 = p;

        p = new ListNode(-4);
        p2->next = p;
        p2 = p;

        p2->next = h->next;
*/        

        Solution s;
        int r = s.hasCycle(h);
        cout << r << endl;
}
