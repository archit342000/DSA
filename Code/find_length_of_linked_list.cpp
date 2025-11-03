// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1
// Difficulty: Easy
// Tags: Linked Lists

/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        int i=0;
        while(head){
            head=head->next;
            i++;
        }
        return i;
    }
};