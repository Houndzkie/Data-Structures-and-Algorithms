#include <iostream>
#define MAX 100 // maximum size of the queue;
using namespace std;

class Queue {
  private:
    int arr[MAX];
    int front, rear;

  public:
    Queue() {
      front = -1;
      rear = -1;
    }

    // Add element to the rear
    void enqueue(int x) {
      if (rear >= MAX - 1) {
        cout << "Queue Overflow\n";
        return;
      }

      if (front == -1) front = 0; // first element inserted
      arr[++rear] = x;
      cout << x << " enqueued to queue\n";
    }

    // Remove and return the front element
    int dequeue() {
      if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return -1;
      }

      return arr[front++];
    }

    // Get the front element without removing it
    int peek() {
      if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
        return -1;
      }

      return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
      return front == -1 || front > rear;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << q.dequeue() << " dequeued from queue\n";
    std::cout << "Front element is " << q.peek() << "\n";

    return 0;
}