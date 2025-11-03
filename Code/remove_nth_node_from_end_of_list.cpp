// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Difficulty: Medium
// Tags: Linked Lists, Two Pointers

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){
            return NULL;
        }
        ListNode *fast=head, *slow=head;

        for(int i=0; i<n; i++){
            fast=fast->next;
        }

        if(!fast){
            return head->next;
        }

        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode *delNode=slow->next;
        slow->next=slow->next->next;
        delNode->next=NULL;
        delete delNode;
        return head;
    }
};