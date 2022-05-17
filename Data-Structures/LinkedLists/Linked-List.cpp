#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *next;

    // Constructor without given data
    Node () {
      data = 0;
      next = NULL;
    }

    // Constructor with int parameter
    Node(int data) {
        this->data = data;
        this->next = NULL;
    };
};

// Singly Linked List
class SinglyLinkedList {
    Node *head;
    int length;

    public:
      SinglyLinkedList() {
        head = NULL;
        length = 0;
      }
      void printList();
      void append(int value);
      void prepend(int value);
      void get(int index);
      void set(int index, int newValue);
};

  // Print contents of current Linked List
  void SinglyLinkedList::printList() {
    Node *temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
  };

  // Function to append a new node to end of list
  void SinglyLinkedList::append(int value) {
    // Create new Node.
    Node *newNode = new Node(value);
  
    // Assign new node to head if head hasn't been set
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    Node *temp = head;
    // Traverse until end of list is reached
    // tail will point to NULL at end of list
    while (temp->next != NULL) {
        // Update temp as we go
        temp = temp->next;
    }
  
    // When tail is found insert temp at the end as what temp next is pointing to
    temp->next = newNode;
    // increment length
    length++;
}

void SinglyLinkedList::prepend(int value) {

}


int main()
{
  return 0;
}