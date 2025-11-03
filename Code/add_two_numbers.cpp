// https://leetcode.com/problems/add-two-numbers/description/
// Difficulty: Medium
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1=l1, *ptr2=l2;
        ListNode *dummyHead=new ListNode();
        ListNode *ptr3=dummyHead;

        int carry=0;

        while(ptr1 && ptr2){
            int sum = ptr1->val + ptr2->val + carry;

            ListNode *newNode = new ListNode(sum%10);
            carry=sum/10;

            ptr3->next=newNode;
            ptr3=ptr3->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        while(ptr1){
            int sum=ptr1->val+carry;
            ListNode *newNode = new ListNode(sum%10);
            carry=sum/10;

            ptr3->next=newNode;
            ptr3=ptr3->next;
            ptr1=ptr1->next;
        }

        while(ptr2){
            int sum=ptr2->val+carry;
            ListNode *newNode = new ListNode(sum%10);
            carry=sum/10;

            ptr3->next=newNode;
            ptr3=ptr3->next;
            ptr2=ptr2->next;
        }

        if(carry){
            ListNode *newNode = new ListNode(carry);
            ptr3->next=newNode;
        }

        return dummyHead->next;
    }
};