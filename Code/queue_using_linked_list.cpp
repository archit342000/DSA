// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
// Difficulty: Easy
// Tags: Queues, Linked Lists

class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node *front;
    Node *back;
    int count;

  public:
    myQueue() {
        // Initialize your data members
        front=back=NULL;
        count=0;
    }

    bool isEmpty() {
        // check if the queue is empty,
        return count==0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node *newNode = new Node(x);
        if(count){
            back->next=newNode;
            back=back->next;
        }
        else{
            front=back=newNode;
        }
        count++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(count){
            front=front->next;
            count--;
        }
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(count){
            return front->data;
        }
        return -1;
    }

    int size() {
        // Returns the current size of the queue.,
        return count;
    }
};
