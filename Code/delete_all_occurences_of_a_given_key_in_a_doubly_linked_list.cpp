// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
// Difficulty: Medium
// Tags: Doubly Linked Lists

// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node *head = *head_ref;
        
        Node *dummyHead = new Node();
        dummyHead->next=head;
        
        Node *ptr=head, *prev=dummyHead;
        
        while(ptr){
            if(ptr->data==x){
                prev->next=ptr->next;
                ptr->next=NULL;
                ptr=prev->next;
            }
            else{
                prev=ptr;
                ptr=ptr->next;
            }
        }
        
        *head_ref = dummyHead->next;
    }
};