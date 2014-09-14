#include <iostream>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x=0) : val(x), next(NULL) {}
};

class Solution {
public:
        bool countk(ListNode *head, int k) {
                while (k--) {
                        if (head == NULL)
                                return false;
                        head = head->next;
                }
                return true;
        }

        ListNode *reverseKGroup(ListNode *head, int k) {
                ListNode **last_tail = &head;
                ListNode *cur, *next, *prev, *org_first;

                while (1) {
                        if (!countk(*last_tail, k))
                            break;
                        
                        org_first = *last_tail;
                        cur = *last_tail;
                        for (int i = 0; i < k; i++) {
                                next = cur->next;
                                cur->next = prev;
                                prev = cur;
                                cur = next;
                        }
                        (*last_tail)->next = next;
                        *last_tail = prev;
                        last_tail = &org_first->next;
                            
                }
                return head;
        }
};

int main()
{
        const int N = 8;
        ListNode l[N];
        for (int i = 0; i < N; i++) {
                l[i].val = i;
                l[i].next = &l[i+1];
        }
        l[N-1].next = NULL;
        Solution s;
        auto ret = s.reverseKGroup(l, 3);

        while (ret) {
                cout << ret->val << " ";
                ret = ret->next;
        }
        cout << endl;
        
}
