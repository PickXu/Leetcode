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

    ListNode *mergeKLists(vector<ListNode *> &lists) {

        if (lists.size() == 0) return NULL;

        if (lists.size() == 1) return lists[0];

        if (lists.size() == 2) {

            ListNode *thead=NULL, *ttail=NULL;

            int index;

            if (lists[0] == NULL && lists[1] == NULL) return thead;

            else if (lists[0] != NULL && lists[1] == NULL) {

                thead = lists[0];

                index = 0;

            } else if (lists[0] == NULL && lists[1] != NULL) {

                thead = lists[1];

                index = 1;

            } else if (lists[0]->val < lists[1]->val) {

                thead = lists[0];

                index = 0;

            } else {

                thead = lists[1];

                index = 1;

            }

            ttail = thead;

            lists[index] = lists[index]->next;

            while(1){

                if (lists[0] == NULL && lists[1] == NULL) return thead;

                else if (lists[0] == NULL && lists[1] != NULL) {

                    ttail->next = lists[1];

                    ttail = lists[1];

                    index = 1;

                } else if (lists[0] != NULL && lists[1] == NULL) {

                    ttail->next = lists[0];

                    ttail = lists[0];

                    index = 0;

                } else if (lists[0]->val < lists[1]->val) {

                    ttail->next = lists[0];

                    ttail = lists[0];

                    index = 0;

                } else {

                    ttail->next = lists[1];

                    ttail = lists[1];

                    index = 1;

                }

                lists[index] = lists[index]->next;

            }

        }

        vector<ListNode*> tlists;

        vector<ListNode*> left, right;

        int i;

        for(i=0;i<lists.size()/2;i++)

            left.push_back(lists[i]);

        for(i=lists.size()/2;i<lists.size();i++)

            right.push_back(lists[i]);

        tlists.push_back(mergeKLists(left));

        tlists.push_back(mergeKLists(right));

        return mergeKLists(tlists);

    }

};
