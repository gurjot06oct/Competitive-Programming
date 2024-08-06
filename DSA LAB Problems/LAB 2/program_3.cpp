#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& arr, const vector<int>& elems, const vector<int>& positions) {
    vector<int> newArr(arr.size() + elems.size());
    int oldind = 0, newind = 0;
    for (int i = 0; i < elems.size(); ++i) {
        while (newind < (positions[i] + i)) {
            newArr[newind++] = arr[oldind++];
        }
        newArr[newind++] = elems[i];
    }
    while (oldind < arr.size()) {
        newArr[newind++] = arr[oldind++];
    }
    arr = newArr;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int num;
    cout << "Enter the number of elements to insert: ";
    cin >> num;

    vector<int> elements(num);
    vector<int> positions(num);

    for (int i = 0; i < num; ++i) {
        cout << "Enter element " << i + 1 << " and its position: ";
        cin >> elements[i] >> positions[i];
    }

    insert(arr, elements, positions);

    cout << "Array after insertion: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
