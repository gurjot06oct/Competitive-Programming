#include <iostream>
using namespace std;

void insert(int arr[], int& size, int cap, int val, int pos) {
    if (pos < 0 || pos > size) {
        cout << "invalid position" << endl;
        return;
    }
    if (size >= cap) {
        cout << "Array is full." << endl;
        return;
    }
    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;
}

int main() {
    int capacity,size;
    cout << "Enter the capacity of the array: ";
    cin >> capacity;
    int* arr = new int[capacity];
    
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int val, pos;
    cout << "Enter the element to insert: ";
    cin >> val;
    cout << "Enter the position to insert the element at (0-based): ";
    cin >> pos;

    insert(arr, size, capacity, val, pos);

    // Print After Insertion
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
