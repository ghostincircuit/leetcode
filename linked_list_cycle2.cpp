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
        bool helper(ListNode *head, int *ret) {
                ListNode *fast = head;
                ListNode *slow = head;
                int steps = 1;

                if (head == NULL)
                        return false;
                while (1) {
                        slow = slow->next;
                        if (fast == NULL)
                                return false;
                        fast = fast->next;
                        if (fast == NULL)
                                return false;
                        fast = fast->next;
                        if (fast == slow) {
                                *ret = steps;
                                return true;
                        } else {
                                steps++;
                        }

                }
        }

        ListNode *detectCycle(ListNode *head) {
                int n;
                bool r = helper(head, &n);
                ListNode *end = head;
                ListNode *front = head;
                if (!r)
                        return NULL;

                while (n--) {
                        front = front->next;
                }

                while (front != end) {
                        front = front->next;
                        end = end->next;
                }
                return end;
        }
};

int main()
{
        Solution s;

/*
        ListNode *h = new ListNode(0);
        h->next = h;
        assert(s.detectCycle(h) == h);
*/

/*
        ListNode *h = new ListNode(0);
        ListNode *p = new ListNode(1);
        h->next = p;
        p->next = p;
        assert(s.detectCycle(h) == p);
*/

        ListNode *h = new ListNode(0);
        ListNode *p1 = new ListNode(1);
        ListNode *p2 = new ListNode(2);
        ListNode *p3 = new ListNode(3);
        ListNode *p4 = new ListNode(4);
        ListNode *p5 = new ListNode(5);
        ListNode *p6 = new ListNode(6);
        h->next = p1;
        p1->next = p2;
        p2->next = p3;
        p3->next = p4;
        p4->next = p5;
        p5->next = p6;
        p6->next = p3;
        assert(s.detectCycle(h) == p3);


        return 0;
}
