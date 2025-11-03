// https://leetcode.com/problems/sort-list/description/
// Difficulty: Medium
// Tags: Linked Lists, Sorting, Two Pointers, Algorithms, Divide and Conquer

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
    ListNode* sortList(ListNode* head) {
        ListNode *ptr=head;

        vector<int> v;
        while(ptr){
            v.push_back(ptr->val);
            ptr=ptr->next;
        }

        sort(v.begin(), v.end());

        ptr=head;
        for(int x: v){
            ptr->val=x;
            ptr=ptr->next;
        }

        return head;
    }
};

class Solution {
public:
    ListNode* merge(ListNode *leftHead, ListNode *rightHead){
        ListNode *dummyHead = new ListNode();

        ListNode *ptr=dummyHead;

        while(leftHead && rightHead){
            if(leftHead->val <= rightHead->val){
                ptr->next=leftHead;
                ptr=ptr->next;
                leftHead=leftHead->next;
            }
            else{
                ptr->next=rightHead;
                ptr=ptr->next;
                rightHead=rightHead->next;
            }
        }

        while(leftHead){
            ptr->next=leftHead;
            ptr=ptr->next;
            leftHead=leftHead->next;
        }

        while(rightHead){
            ptr->next=rightHead;
            ptr=ptr->next;
            rightHead=rightHead->next;
        }

        return dummyHead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }   

        ListNode *slow=head, *fast=head, *slowPrev=NULL;

        while(fast && fast->next){
            slowPrev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        slowPrev->next=NULL;

        ListNode *leftHead=sortList(head);
        ListNode *rightHead=sortList(slow);
        return merge(leftHead, rightHead);
    }
};