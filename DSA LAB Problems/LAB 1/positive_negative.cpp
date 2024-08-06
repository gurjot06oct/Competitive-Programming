#include <iostream>
using namespace std;

void swapped(int&a,int&b){
    int temp = a;
    a=b;
    b=temp;
}
int main()
{
    int count = 11;
    int a[11] = {-2,3,4,-5,-1,4,5,-6,1,2,-3};
    int left=0,right=1;
    while (left < 2*(count/2) - 1 && right < 2*(count/2) )
    {
        while (a[left] >= 0)
        {
            left+=2;
        }
        while (a[right] < 0)
        {
            right+=2;
        }
        swapped(a[left],a[right]);
        left+=2;
        right+=2;
    }
    if(count&1 == 1 && a[count-1] )
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
    return 0;

    
}