#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    LinkedList(int *arr, int size)
    {
        this->fromArray(arr, size);
    }
    // From array
    void fromArray(int *arr, int size)
    {
        if (head == nullptr)
        {
            if (size > 0)
            {
                head = new Node(arr[0]);
                Node *temp = head;
                for (int i = 1; i < size; i++)
                {
                    temp = temp->next = new Node(arr[i]);
                }
            }
            else
            {
                cout << "Invalid size!" << endl;
            }
        }
        else
        {
            cout << "Linked List must be Empty." << endl;
        }
    }
    // Display the list
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NUll" << endl;
    }
    void reverseList()
    {
        Node *prev = nullptr, *current = head, *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head=prev;
    }
};

int main()
{
    LinkedList list;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    list.fromArray(arr, size);
    list.display();
    list.reverseList();
    list.display();
    return 0;
}
