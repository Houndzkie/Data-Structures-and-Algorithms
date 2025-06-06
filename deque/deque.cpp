#include <iostream>
#define MAX 100
using namespace std;

class Deque {
  private:
    int arr[MAX];
    int front, rear;

  public:
    Deque() {
      front = -1;
      rear = -1;
    }

    // Check if deque is full
    bool isFull() {
      return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    // Check if deque is empty
    bool isEmpty() {
      return front == -1;
    }

    // Insert at front
    void insertFront(int x) {
      if (isFull()) {
        cout << "Deque Overflow (front)\n";
        return;
      }

      // First element
      if (front == -1) front = rear = 0;
      else if (front == 0) front = MAX - 1;
      else front--;
      
      arr[front] = x;
      cout << x << " inserted at front\n";
    }

    // Insert at rear
    void insertRear(int x) {
      if (isFull()) {
        cout << "Deque Overlow (rear)\n";
        return;
      }

      // First element
      if (front == -1) front = rear = 0;
      else if (rear == MAX - 1) rear = 0;
      else rear++;

      arr[rear] = x;
      cout << x << " inserted at rear\n";
    }

    // Delete from front
    int deleteFront() {
      if (isEmpty()) {
        cout << "Deque Underflow (front)\n";
        return -1;
      }

      int val = arr[front];

      if (front == rear) front = rear = -1; // deque becomes empty
      else if (front == MAX - 1) front = 0;
      else front++;

      return val;
    }

    // Delete from rear
    int deleteRear() {
      if (isEmpty()) {
        cout << "Deque Underflow (rear)\n";
        return -1;
      }

      int val = arr[rear];

      if (front == rear) front = rear = -1; // deque becomes empty
      else if (rear == 0) rear = MAX - 1;
      else rear--;

      return val;
    }

    // Get front element
    int getFront() {
      if (isEmpty()) {
        cout << "Deque Underflow (front)\n";
        return -1;
      }

      return arr[front];
    }

    // Get rear element
    int getRear() {
      if (isEmpty()) {
        cout << "Deque Underflow (rear)\n";
        return -1;
      }

      return arr[rear];
    }
};

int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    std::cout << "Front element: " << dq.getFront() << "\n";
    std::cout << "Rear element: " << dq.getRear() << "\n";

    std::cout << dq.deleteRear() << " deleted from rear\n";
    std::cout << dq.deleteFront() << " deleted from front\n";

    return 0;
}