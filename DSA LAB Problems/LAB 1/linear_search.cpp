#include <iostream>
using namespace std;

int main()
{
    int n,s,res=-1;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {   
        cin>>arr[i];
    }
    cout<<"Element to be searched: "<<endl;
    cin >> s;
    for (int i = 0; i < n; i++)
    {   
        if(arr[i]==s)
        res=i;
    }
    if(res == -1){
        cout<< "Element not found";
    }else{
        cout<<res<<endl;
    }
    return 0;
}