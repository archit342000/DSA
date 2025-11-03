// https://www.geeksforgeeks.org/problems/find-length-of-loop/1
// Difficulty: Medium
// Tags: Linked Lists, Two Pointers

/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow=head, *fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                int l=1;
                slow=slow->next;
                
                while(slow!=fast){
                    slow=slow->next;
                    l++;
                }
                
                return l;
            }
        }
        
        return 0;
    }
};