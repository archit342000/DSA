// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Difficulty: Hard
// Tags: Linked Lists

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr=head;
        Node *newHead=NULL;

        while(ptr){
            Node *newNode = new Node(ptr->val);
            newNode->next=ptr->next;
            ptr->next=newNode;
            ptr=newNode->next;

            if(newHead==NULL){
                newHead=newNode;
            }
        }

        ptr=head;
        while(ptr){
            if(ptr->random){
                ptr->next->random = ptr->random->next;
            }
            else{
                ptr->next->random = NULL;
            }
            ptr=ptr->next->next;
        }

        ptr=head;
        while(ptr){
            Node *temp=ptr->next->next;
            if(temp){
                ptr->next->next=ptr->next->next->next;
            }
            else{
                ptr->next->next=NULL;
            }
            ptr->next=temp;
            ptr=temp;
        }

        return newHead;
    }
};