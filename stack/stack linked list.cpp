#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

// Stack class
class Stack {
  private:
    Node* topNode;

  public:
    Stack() : topNode(nullptr) {}

    // Push an element onto the stack
    void push(int val) {
      Node* newNode = new Node(val);
      newNode->next = topNode;
      topNode = newNode;
    }

    // Pop the top element
    void pop() {
      if (isEmpty()) {
        cout << "Stack Underflow\n";
        return;
      }

      Node* temp = topNode;
      topNode = topNode->next;
      delete temp;
    }

    // Peek at the top element
    int top() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
      }

      return topNode->data;
    }

    // Check is stack is empty
    bool isEmpty() {
      return topNode == nullptr;
    }

    // Display stack (top to bottom)
    void display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
      }

      Node* temp = topNode;
      cout << "Stack: ";

      while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
      }

      cout << "\n";
    }

    // Destructor to free memory
    ~Stack() {
      while (!isEmpty()) {
        pop();
      }
    }
};

// Test the stack
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();   // Stack: 30 20 10

    cout << "Top: " << s.top() << "\n"; // Top: 30

    s.pop();
    s.display();   // Stack: 20 10

    return 0;
}