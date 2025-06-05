#include <iostream>
using namespace std;

// Node definition
struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
  private:
    Node* head;

  public:
    LinkedList() : head(nullptr) {}

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
    }

    // Insert at the beggining
    void insertAtBeginning(int val) {
      Node* newNode = new Node(val);
      newNode->next = head;
      head = newNode;
    }

    // Delete a node by value
    void deleteValue(int val) {
      if (!head) return;

      if (head->data == val) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
      }

      Node* temp = head;

      while (temp->next && temp->next->data != val) {
        temp = temp->next;
      }

      if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
      }
    }

    // Display list
    void display() {
      Node* temp = head;

      while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
      }

      cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() {
      Node* temp = head;

      while (temp) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
      }
    }
};

// Test the linked list
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.display(); // Output: 5 -> 10 -> 20 -> NULL

    list.deleteValue(10);
    list.display(); // Output: 5 -> 20 -> NULL

    return 0;
}
