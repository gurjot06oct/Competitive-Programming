#include <iostream>
using namespace std;

void insert(int*& arr, int& size, int element) {
    
    int* newArr = new int[size + 1];

    int i=0;
    while(arr[i]<=element){
        newArr[i] = arr[i];
        i++;
    }
    newArr[i++] = element;
    while(i<=size){
        newArr[i] = arr[i-1];
        i++;
    }
    delete[] arr;
    arr = newArr;
    size++;
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int element;
    cout << "Enter the element to insert: ";
    cin >> element;

    insert(arr, size, element);

    // Print after insertion
    cout << "Array after insertion: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;

    return 0;
}
