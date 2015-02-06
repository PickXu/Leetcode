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

    void reorderList(ListNode *head) {

        if (head == NULL) return;

        std::stack<ListNode*> mystack;

        int length=0;

        ListNode* tmp = head;

        while (tmp != NULL ) {

            tmp=tmp->next;

            length++;

        }

        tmp = head;

        int half = length/2;

        length = 0;

        while (tmp != NULL) {

            if (length > half) {

                mystack.push(tmp);

            }

            length++;

            tmp = tmp->next;

        }

        length=0;

        tmp = head;

        while (length < half) {

            if (!mystack.empty()) {

                ListNode* ttmp = mystack.top();

                ttmp->next = tmp->next;

                tmp->next = ttmp;

                tmp = tmp->next;

            }

            tmp = tmp->next;

            length++;

            mystack.pop();

        }

        tmp->next = NULL;



        return;

    }

};
