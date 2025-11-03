// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// Difficulty: Easy
// Tags: Linked Lists

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        
        Node *zeroHead = new Node(99), *oneHead = new Node(99), *twoHead = new Node(99);
        Node *zeroPtr = zeroHead, *onePtr = oneHead, *twoPtr = twoHead;
        
        while(head!=NULL){
            int data = head->data;
            
            if(data==0){
                zeroPtr->next = head;
                zeroPtr = zeroPtr->next;
            }
            else if(data==1){
                onePtr->next = head;
                onePtr = onePtr->next;
            }
            else{
                twoPtr->next = head;
                twoPtr = twoPtr->next;
            }
            
            head = head->next;
        }
        
        if(zeroHead->next!=NULL){
            if(oneHead->next!=NULL){
                zeroPtr->next = oneHead->next;
                if(twoHead->next!=NULL){
                    onePtr->next = twoHead->next;
                    twoPtr->next = NULL;
                }
                else{
                    onePtr->next = NULL;
                }
            }
            else{
                if(twoHead->next!=NULL){
                    zeroPtr->next = twoHead->next;
                    twoPtr->next = NULL;
                }
                else{
                    zeroPtr->next = NULL;
                }
            }
            return zeroHead->next;
        }
        else if(oneHead->next!=NULL){
            if(twoHead->next!=NULL){
                onePtr->next = twoHead->next;
                twoPtr->next = NULL;
            }
            else{
                onePtr->next = NULL;
            }
            return oneHead->next;
        }
        else{
            return twoHead->next;
        }
    }
};