#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
  private:
    Node* frontNode;
    Node* rearNode;

  public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    // Enqueue (insert at rear)
    void enqueue(int val) {
      Node* newNode = new Node(val);

      if (isEmpty()) {
        frontNode = rearNode = newNode;
      } else {
        rearNode->next = newNode;
        rearNode = newNode;
      }
    }

    // Dequeue (remove from front)
    void dequeue() {
      if (isEmpty()) {
        cout << "Queue Underflow\n";
        return;
      }

      Node* temp = frontNode;
      frontNode = frontNode->next;
      delete temp;

      if (!frontNode) {
        rearNode = nullptr; // queue became empty
      }
    }

    // Peak front element
    int front() {
      if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
      }

      return frontNode->data;
    }

    // Check if empty
    bool isEmpty() {
      return frontNode == nullptr;
    }

    // Display queue from front to rear
    void display() {
      if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
      }

      Node* temp = frontNode;
      cout << "Queue: ";

      while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
      }

      cout << "\n";
    }

    // Destructor
    ~Queue() {
      if (!isEmpty()) {
        dequeue();
      }
    }
};

// Test the queue
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: Queue: 10 20 30

    cout << "Front: " << q.front() << "\n"; // Output: 10

    q.dequeue();
    q.display(); // Output: Queue: 20 30

    return 0;
}