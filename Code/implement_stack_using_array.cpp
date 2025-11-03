// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
// Difficulty: Easy
// Tags: Arrays, Stacks

class myStack {
    int arr[1000];
    int top;
    int maxSize;
  public:
    myStack(int n) {
        // Define Data Structures
        top=-1;
        maxSize=n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==-1;
    }

    bool isFull() {
        // check if the stack is full
        return top==maxSize-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(!isFull()){
            arr[++top]=x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(!isEmpty()){
            top--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(!isEmpty()){
            return arr[top];
        }
        return -1;
    }
};