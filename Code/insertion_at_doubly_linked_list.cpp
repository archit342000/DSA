// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
// Difficulty: Easy
// Tags: Doubly Linked Lists

/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node *newNode = new Node(x);
        
        if(!head){
            return newNode;
        }
        
        
        int i=0;
        Node *ptr=head;
        while(ptr && i<p){
            ptr=ptr->next;
            i++;
        }
        
        newNode->prev=ptr;
        
        if(ptr->next){
            ptr->next->prev=newNode;
        }
        
        newNode->next=ptr->next;
        ptr->next=newNode;
        
        return head;
    }
};