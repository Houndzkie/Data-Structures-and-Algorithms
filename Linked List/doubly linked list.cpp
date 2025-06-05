#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
  int data;
  Node* next;
  Node* prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList {
  private:
    Node* head;

  public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at end
    void insertAtEnd(int val) {
      Node* newNode = new Node(val);
      
      if (!head) {
        head = newNode;
        return;
      }

      Node* temp = head;

      while (temp->next) {
        temp = temp->next;
      }

      temp->next = newNode;
      newNode->prev = temp;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
      Node* newNode = new Node(val);

      if (!head) {
        head = newNode;
        return;
      }

      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    // Delete node by value
    void deleteValue(int val) {
      if (!head) return;

      Node* temp = head;

      if (temp->data == val) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
      }

      while (temp && temp->data != val) {
        temp = temp->next;
      }

      if (!temp) return;
      if (temp->next) temp->next->prev = temp->prev;
      if (temp->prev) temp->prev->next = temp->next;

      delete temp;
    }

    // Display forward
    void displayForward() {
      Node* temp = head;
      cout << "Forward: ";

      while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
      }

      cout << "NULL\n";
    }

    // Display backward
    void displayBackward() {
      if (!head) {
        cout << "NULL\n";
        return;
      }

      Node* temp = head;

      while (temp->next) {
        temp = temp->next;
      }

      cout << "Backward: ";

      while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
      }

      cout << "NULL\n";
    }

    // Destructor
    ~DoublyLinkedList() {
      Node* temp = head;

      while (temp) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
      }
    }
};

// Test it
int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.insertAtBeginning(1);

    dll.displayForward();  // Output: 1 <-> 5 <-> 10 <-> 20 <-> NULL
    dll.displayBackward(); // Output: 20 <-> 10 <-> 5 <-> 1 <-> NULL

    dll.deleteValue(10);
    dll.displayForward();  // Output: 1 <-> 5 <-> 20 <-> NULL

    return 0;
}