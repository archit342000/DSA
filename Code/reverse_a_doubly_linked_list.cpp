// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// Difficulty: Easy
// Tags: Doubly Linked Lists

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // Your code here
        Node *prev=NULL;
        Node *curr=head;

        while(curr){
            curr->prev=curr->next;
            curr->next=prev;
            prev=curr;
            curr=curr->prev;
        }
        
        return prev;
    }
};