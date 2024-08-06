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

    // binary search
    int left =0,right= n-1,mid;
    while(left<right){
        mid = left + (right-left)/2;
        if(arr[mid] == s){
            res=mid;
            break;
        }else if(arr[mid] > s){
            right = mid-1;
        }else{
            left= mid +1;
        }
    }


    if(res == -1){
        cout<< "Element not found";
    }else{
        cout<<res<<endl;
    }
    return 0;
}