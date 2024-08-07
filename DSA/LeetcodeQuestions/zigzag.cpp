#include <iostream>
#include<string>
using namespace std;

int main()
{
    std::string s= "abcdefghijklmnopqrstuvwxyz";
    int numRows = 5;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < s.size();j+=2*(numRows-1))
        {
            cout<<s[j];
            for (int k = 0; k < numRows-2-i; k++)
            {
                cout<<" ";
            }
            for (int k = 0; k < i-1; k++)
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}