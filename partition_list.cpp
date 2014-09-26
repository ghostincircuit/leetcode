/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:

    ListNode *partition(ListNode *head, int x) {

        ListNode *small = NULL;

        ListNode *big = NULL;

        ListNode **stail = &small;

        ListNode **btail = &big;

        while (head) {

            if (head->val < x) {

                *stail = head;

                stail = &head->next;

                head = head->next;

            } else {

                *btail = head;

                btail = &head->next;

                head = head->next;

            }

        }

        *stail = big;

        *btail = NULL;

        return small;

    }

};
