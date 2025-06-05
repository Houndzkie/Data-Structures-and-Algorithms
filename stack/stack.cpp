#include <iostream>
#define MAX 100 // maximum size of stack
using namespace std;

class Stack {
  private:
    int arr[MAX];
    int top;

  public:
    Stack() {
      top = -1;
    }

    // Add element to the top
    void push(int x) {
      if (top >= MAX - 1) {
        cout << "Stack Overflow\n";
        return;
      }

      arr[++top] = x;
      cout << x << " pushed into stack\n";
    }

    // Remove and return the top element
    int pop() {
      if (top < 0) {
        cout << "Stack underflow\n";
        return -1;
      }

      return arr[top--];
    }

    // Return top element without removing
    int peek() {
      if (top < 0) {
        cout << "Stack is Empty\n";
        return -1;
      }

      return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
      return top < 0;
    }

    // Check if stack is full
    bool isFull() {
      return top >= MAX - 1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.pop() << " popped from stack\n";
    std::cout << "Top element is " << s.peek() << "\n";

    return 0;
}