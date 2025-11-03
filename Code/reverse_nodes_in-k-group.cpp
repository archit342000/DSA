// https://leetcode.com/problems/reverse-nodes-in-k-group/
// Difficulty: Hard
// Tags: Doubly Linked Lists, Recursion

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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode *dummyHead=new ListNode();
        dummyHead->next=head;

        ListNode *prev=dummyHead;
        ListNode *last=head;
        while(last){
            int i=1; 
            while(i<k){
                i++;
                last=last->next;
                if(!last){
                    return dummyHead->next;
                }
            }

            last=last->next;

            ListNode *curr=prev->next;
            ListNode *next=curr->next;

            while(next!=last){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }

            prev=curr;
        }

        return dummyHead->next;
    }
};

class Solution {
public:
    ListNode *reverseList(ListNode *head, ListNode *tail){
        if(head==tail){
            return head;
        }

        ListNode *newHead = reverseList(head->next, tail);

        head->next->next=head;
        head->next=NULL;

        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode *dummyHead=new ListNode();
        dummyHead->next=head;

        ListNode *prev=dummyHead;
        ListNode *last=head;
        while(last){
            int i=1; 
            while(i<k){
                i++;
                last=last->next;
                if(!last){
                    return dummyHead->next;
                }
            }

            ListNode *nextLast=last->next;
            ListNode *start=prev->next;
            ListNode *newHead=reverseList(start, last);

            prev->next=newHead;
            start->next=nextLast;
            prev=start;
            last=nextLast;
        }

        return dummyHead->next;
    }
};

