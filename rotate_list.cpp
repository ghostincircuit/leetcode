#include <iostream>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
        ListNode() : val(0), next(NULL) {}
};

class Solution {
public:
        ListNode *rotateRight(ListNode *head, int k) {
                if (!head || !k)
                        return head;
                int i = k;
                ListNode **pp2 = &head;
                ListNode **pp1 = &head;
                while (i && *pp2) {
                        pp2 = &(*pp2)->next;
                        i--;
                }
                if (i) {
                        int len = k - i;
                        k = k%len;
                        if (!k)
                                return head;
                        pp2 = &head;
                        while (k && *pp2) {
                                pp2 = &(*pp2)->next;
                                k--;
                        }
                }
                while (*pp2) {
                        pp1 = &(*pp1)->next;
                        pp2 = &(*pp2)->next;
                }
                ListNode *save = *pp1;
                *pp1 = NULL;
                *pp2 = head;
                return save;
        }
};

void pt(ListNode *p) {
        while (p) {
                cout << p->val << ' ';
                p = p->next;
        }
        cout << endl;
}

int main()
{
        const int N = 1;
        ListNode n[N];
        for (int i = 0; i < N; i++) {
                n[i].val = i+1;
                n[i].next = n+i+1;
        }
        n[N-1].next = NULL;

        ListNode *h = n;
        pt(h);

        Solution s;
        ListNode *r = s.rotateRight(h, 3);
        pt(r);
        return 0;
}
