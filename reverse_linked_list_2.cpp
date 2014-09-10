#include <iostream>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
                m--;
                if (head == NULL)
                        return NULL;
                auto to_mod = &head;
                auto cur = head;
                auto cnt = 0;
                while (cnt != m) {
                        cnt++;
                        to_mod = &cur->next;
                        cur = cur->next;
                }
                auto last_next = &cur->next;
                auto prev = cur;
                while (cnt != n) {
                        cnt++;
                        auto next_cur = cur->next;
                        cur->next = prev;
                        prev = cur;
                        cur = next_cur;
                }
                *to_mod = prev;
                *last_next = cur;
                return head;
        }
};

void travel(ListNode *head)
{
        while (head) {
                cout << head->val << " ";
                head = head->next;
        }
        cout << endl;
}

int main()
{
        ListNode n0(0);
        ListNode n1(1);
        ListNode n2(2);
        ListNode n3(3);
        n0.next = &n1;
        n1.next = &n2;
        n2.next = &n3;
        auto h = &n0;
        travel(h);

        Solution s;
        //h = s.reverseBetween(h,1,4);
        h = s.reverseBetween(h,1,3);
        travel(h);
        return 0;
}
