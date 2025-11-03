// https://leetcode.com/problems/rotate-list/description/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode *ptr=head;
        int n=0;

        while(ptr){
            n++;
            ptr=ptr->next;
        }

        k=k%n;

        ptr=head;
        ListNode *pivot=head;
        int count=1;
        while(ptr->next){
            ptr=ptr->next;
            count++;
            if(count==(n-k)){
                pivot=ptr;
            }
        }

        ptr->next=head;
        head=pivot->next;
        pivot->next=NULL;
        return head;
    }
};