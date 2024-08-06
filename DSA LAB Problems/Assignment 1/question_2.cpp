#include <iostream>
using namespace std;

int main() {
    int size,k;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];
    int * newarr= new int[size];
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "Enter Rotating Index: ";
    cin>>k;
    k= k%size;
    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 1; j <= size/k; j++)
    //     {
    //         swap(arr[i],arr[(i+j*k)%size]);
    //     }
    // }
    for (int i = 0; i < size; i++)
    {
        newarr[(i+k)%size]= arr[i];
    }
    
    for (int i = 0; i < size; ++i) {
        cout<<newarr[i]<<" ";
    }
    cout<<endl;
    

}