// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
// Difficulty: Easy
// Tags: Doubly Linked Lists

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if(!head || !head->next){
            return NULL;
        }
        
        int i=1;
        Node *ptr=head;
        while(ptr && i<x){
            ptr=ptr->next;
            i++;
        }
        
        // First position
        if(x==1){
            ptr->next->prev=NULL;
            head=ptr->next;
            ptr->next=NULL;
        }
        // Last position
        else if(!ptr->next){
            ptr->prev->next=NULL;
            ptr->prev=NULL;
        }
        else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            ptr->next=NULL;
            ptr->prev=NULL;
        }
        
        return head;
    }
};