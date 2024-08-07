#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    string s = "carrace";
    string t = "racecar";
    if(s.length()!= t.length()){
        return false;
    }
    vector<int> mapped(26,0);
    for (int i = 0; i < s.length(); i++)
    {
        mapped[s[i]-'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        mapped[t[i]-'a']--;
    }
    for (int count: mapped)
    {
        if(count != 0){
            return false;
        }
    }
    return true;
}