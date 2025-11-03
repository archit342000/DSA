// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// Difficulty: Medium
// Tags: Linked Lists

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(!head || !head->next){
            return head;
        }
        
        Node *newHead = reverse(head->next);
        
        head->next->next=head;
        head->next=NULL;
        
        return newHead;
    }
    Node* addOne(Node* head) {
        head=reverse(head);
        
        Node *ptr=head;
        Node *prev=NULL;
        int carry=0;
        
        carry=(ptr->data+1)/10;
        ptr->data = (ptr->data+1)%10;
        
        prev=ptr;
        ptr=ptr->next;
        
        while(ptr){
            ptr->data=ptr->data+carry;
            carry=ptr->data/10;
            ptr->data=ptr->data%10;
            prev=ptr;
            ptr=ptr->next;
        }
        
        if(carry){
            prev->next = new Node(carry);
        }
        
        return reverse(head);
    }
};