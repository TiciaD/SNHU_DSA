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
    Node *tail;
    int length;

    public:
      SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
      }
      void printList();
      void append(int value);
      void prepend(int value);
      Node get(int index);
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
  
    // Assign new node to head and tail if head hasn't been set
    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
      tail->next = newNode;
      tail = newNode;
    };

    // increment length
    length++;
}

// Function to prepend node to beginning of list
void SinglyLinkedList::prepend(int value) {
  // Create new Node.
  Node *newNode = new Node(value);

  // Assign new node to head if head hasn't been set
  if (head == NULL) {
      head = newNode;
      tail = head;
      return;
  }

  newNode->next = head;
  head = newNode;
  length++;
}

Node SinglyLinkedList::get(int index) {
    int counter = 0;
    Node *current = head;
    while (counter != index) {
      current = current->next;
      counter++;
    }
    cout << current->data << endl;
    return *current;
}

int main()
{
  SinglyLinkedList list;
  list.append(5);
  list.append(4);
  list.append(3);
  list.printList();
  cout << endl;
  list.prepend(6);
  list.printList();
  cout << endl;
  list.get(2);
  return 0;
}