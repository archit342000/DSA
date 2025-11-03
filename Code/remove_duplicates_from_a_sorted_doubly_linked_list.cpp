// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
// Difficulty: Easy
// Tags: Doubly Linked Lists

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        
        Node *curr=head;
        
        while(curr){
            Node *next=curr->next;
            while(next && next->data==curr->data){
                next=next->next;
            }
            if(next){
                next->prev=curr;
            }
            curr->next=next;
            curr=curr->next;
        }
        
        return head;
    }
};