// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Difficulty: Easy
// Tags: Linked Lists, Two Pointers

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA=headA;
        ListNode *ptrB=headB;

        while(ptrA!=ptrB){
            ptrA=ptrA?ptrA->next:headB;
            ptrB=ptrB?ptrB->next:headA;
        }

        return ptrA;
    }
};