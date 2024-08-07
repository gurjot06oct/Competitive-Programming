#include<iostream>
using namespace std;

int main(){
    string s = "abc";
    string t = "ahbgdc";
    int j=0;
    for (int i = 0; i < t.length(); i++)
    {
        if(t[i]==s[j]){
            j++;
        }
    }
    if(j == s.length()){
        cout<<true<<endl;
    }else{
        cout<<false<<endl;
    }
    
    return true;
}