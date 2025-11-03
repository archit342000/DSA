// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
// Difficulty: Easy
// Tags: Stacks, Linked Lists

/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
    Node *top;
    int count=0;
  public:
    myStack() {
        // Initialize your data members
        top=NULL;
        count=0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return count==0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node *newNode = new Node(x);
        newNode->next=top;
        top=newNode;
        count++;
    }

    void pop() {
        // Removes the top element of the stack
        if(top){
            top=top->next;
            count--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(top){
            return top->data;
        }
        return -1;
    }

    int size() {
        // Returns the current size of the stack.
        return count;
    }
};