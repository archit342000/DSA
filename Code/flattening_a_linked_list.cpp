// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Difficulty: Medium
// Tags: Linked Lists

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *merge(Node *l1, Node *l2){
        Node *ptr1=l1, *ptr2=l2;
        
        Node *dummyHead = new Node(-1);
        Node *ptr3=dummyHead;
        
        while(ptr1 && ptr2){
            if(ptr1->data<=ptr2->data){
                ptr3->bottom=ptr1;
                ptr1=ptr1->bottom;
                ptr3=ptr3->bottom;
            }
            else{
                ptr3->bottom=ptr2;
                ptr2=ptr2->bottom;
                ptr3=ptr3->bottom;
            }
        }
        
        while(ptr1){
            ptr3->bottom=ptr1;
            ptr1=ptr1->bottom;
            ptr3=ptr3->bottom;
        }
        
        while(ptr2){
            ptr3->bottom=ptr2;
            ptr2=ptr2->bottom;
            ptr3=ptr3->bottom;
        }
        
        return dummyHead->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(!root || !root->next){
            return root;
        }
        
        root->next=flatten(root->next);
        
        return merge(root, root->next);
    }
};