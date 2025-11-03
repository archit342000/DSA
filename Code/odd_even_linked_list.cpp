// https://leetcode.com/problems/odd-even-linked-list/description/
// Difficulty: Easy
// Tags: Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode *oddHead = new ListNode();
        ListNode *evenHead = new ListNode();

        ListNode *oddPtr=oddHead;
        ListNode *evenPtr=evenHead;
        ListNode *ptr=head;

        int i=1;

        while(ptr){
            // odd
            if(i%2){
                oddPtr->next=ptr;
                oddPtr=oddPtr->next;
            }
            //even
            else{
                evenPtr->next=ptr;
                evenPtr=evenPtr->next;
            }
            ptr=ptr->next;
            i++;
        }

        evenPtr->next=NULL;
        oddPtr->next=evenHead->next;
        return oddHead->next;
    }
};