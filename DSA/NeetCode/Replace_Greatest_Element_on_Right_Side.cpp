#include <iostream>
using namespace std;

int main()
{
    int arr[]={57010,40840,69871,14425,70605},temp, max;
    int size = sizeof(arr) / sizeof(int);
    max = arr[size - 1];
    arr[size - 1] = -1;
    temp=max;
    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            temp = arr[i];
        }
        arr[i] = max;
        max=temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}