#include <set>
#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
        ListNode *deleteDuplicates(ListNode *head) {
                ListNode **pp = &head;
                set<int> mp;
                while (*pp != NULL) {
                        ListNode *p = *pp;
                        set<int>::iterator i = mp.find(p->val);
                        if (i == mp.end()) {
                                mp.insert(p->val);
                                pp = &(p->next);
                        } else {
                                *pp = p->next;
                                //pp = &(p->next);
                                //delete?
                        }

                }
                return head;
        }
};


int main()
{
        ListNode *head = NULL;
        ListNode *p;

/*
        p = new ListNode(1);
        head = p;

        p = new ListNode(1);
        p->next = head;
        head = p;

        p = new ListNode(1);
        p->next = head;
        head = p;

        p = new ListNode(2);
        p->next = head;
        head = p;

        p = new ListNode(2);
        p->next = head;
        head = p;
*/

        p = new ListNode(1);
        p->next = head;
        head = p;

        p = new ListNode(2);
        p->next = head;
        head = p;

        

        ListNode *p1 = head;
        while (p1 != NULL) {
                cout << p1->val << ' ';
                p1 = p1->next;;
        }
        cout << endl;

        Solution s;
        p1 = head;
        p1 = s.deleteDuplicates(p1);
        while (p1 != NULL) {
                cout << p1->val << ' ';
                p1 = p1->next;;
        }
        cout << endl;

        return 0;
}
