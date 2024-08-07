#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HeaderLinkedList {
private:
    Node* head;
public:
    HeaderLinkedList() {
        head = new Node(); // Create the header node
        head->next = nullptr;
    }
    
    // Insert at the beginning (after the header node)
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head->next;
        head->next = newNode;
    }
    
    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete newNode; // Free the memory allocated for newNode
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display the list
    void display() {
        Node* temp = head->next; // Skip the header node
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Reverse the list
    void reverseList() {
        Node *prev = nullptr, *current = head->next, *next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head->next = prev;
    }
};

int main() {
    HeaderLinkedList list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtEnd(3);
    list.insertAtPosition(4, 2); // Insert 4 at position 2
    list.display(); // Output: 2 -> 1 -> 4 -> 3 -> NULL
    list.reverseList();
    list.display(); // Output: 3 -> 4 -> 1 -> 2 -> NULL

    return 0;
}
