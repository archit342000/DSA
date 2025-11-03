// https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
// Difficulty: Easy
// Tags: Arrays, Queues

class myQueue {
    int arr[1000];
    int maxSize;
    int front;
    int back;

  public:
    myQueue(int n) {
        // Define Data Structures
        maxSize=n;
        front=0;
        back=-1;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front-back==1;
    }

    bool isFull() {
        // check if the queue is full
        return (back-front)==maxSize-1;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(!isFull()){
            arr[++back]=x;
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(!isEmpty()){
            front++;
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(!isEmpty()){
            return arr[front];
        }
        return -1;
    }

    int getRear() {
        // Return the last element of queue
        if(!isEmpty()){
            return arr[back];
        }
        return -1;
    }
};