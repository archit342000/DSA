// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
// Difficulty: Easy
// Tags: Doubly Linked Lists, Two Pointers

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        if(!head->next){
            return ans;
        }
        
        Node *left=head;
        Node *right=head;
        
        while(right && right->next && right->data<=target){
            right=right->next;
        }
        
        while(left->data < right->data){
            int sum=left->data+right->data;
            if(sum==target){
                ans.push_back({left->data, right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum>target){
                right=right->prev;
            }
            else{
                left=left->next;
            }
        }
        
        return ans;
    }
};
