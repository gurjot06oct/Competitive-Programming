#include <iostream>
using namespace std;

void swapped(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int count = 12;
    int a[] = {-2, 3, 4, -5, -1, 4, 5, 0, -6, 1, 2, -3};
    int ptr = 0;
    int zeroindex =-1;
    for (int i = 0; i < count; i++)
    {
        if (a[i] < 0)
        {
            if (a[i] != a[ptr])
            {
                swapped(a[i], a[ptr]);
            }
            ptr++;
        }
        if(a[i]==0){
            zeroindex=i;
        }
    }
    if(zeroindex!=-1){
        swapped(a[ptr],a[zeroindex]);
    }
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}