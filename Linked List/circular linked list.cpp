#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
  private:
    Node* head;

  public:
    CircularLinkedList() : head(nullptr) {}

    // Insert at end
    void insert(int val) {
      Node* newNode = new Node(val);

      if (!head) {
        head = newNode;
        newNode->next = head;
        return;
      }

      Node* temp = head;

      while (temp->next != head) {
        temp = temp->next;
      }

      temp->next = newNode;
      newNode->next = head;
    }

    // Delete by value
    void deleteValue(int val) {
      if (!head) return;

      Node* curr = head;
      Node* prev = nullptr;

      // Special case: deleting head
      if (head->data == val) {
        if (head->next == head) {
          delete head;
          head = nullptr;
          return;
        }

        // Find last node
        Node* last = head;

        while (last->next != head) {
          last = last->next;
        }

        Node* toDelete = head;
        head = head->next;
        last->next = head;
        delete toDelete;
        return;
      }

      // Deleting other nodes
      do {
        prev = curr;
        curr = curr->next;

        if (curr->data == val) {
          prev->next = curr->next;
          delete curr;
          return;
        }
      } while (curr != head);
    }

    // Display list
    void display() {
      if (!head) {
        cout << "List is empty\n";
        return;
      }

      Node* temp = head;

      do {
        cout << temp->data << " -> ";
        temp = temp->next;
      } while (temp != head);

      cout << "(head)\n";
    }

    // Destructor
    ~CircularLinkedList() {
      if (!head) return;

      Node* temp = head->next;

      while (temp != head) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
      }

      delete temp;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.display(); // 10 -> 20 -> 30 -> (head)

    cll.deleteValue(10);
    cll.display(); // 20 -> 30 -> (head)

    return 0;
}