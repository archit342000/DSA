// https://leetcode.com/problems/reverse-linked-list/description/
// Difficulty: Easy
// Tags: Linked Lists, Recursion

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode *newHead = reverseList(head->next);

        ListNode *next=head->next;
        next->next=head;
        head->next=NULL;

        return newHead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *curr=head;
        ListNode *prev=NULL;

        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
};