// https://leetcode.com/problems/palindrome-linked-list/description/
// Difficulty: Easy
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
    ListNode *reverseList(ListNode *head){
        if(!head || !head->next){
            return head;
        }

        ListNode *newHead = reverseList(head->next);

        head->next->next=head;
        head->next=NULL;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow=reverseList(slow);

        fast=head;

        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }

        return true;
    }
};