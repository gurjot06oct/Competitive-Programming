#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool tocheck()
{
    string s = "a."; // abcabcbb
    int left = 0, right = s.length() - 1;
    for (;left < right;)
    {
        for (;s[left] < 65 || (s[left] > 90 && s[left] < 97) || s[left] > 122;)
        {
            if((left+1) < s.length()){
                left++;
            }
        }
        for (;s[right] < 65 || (s[right] > 90 && s[right] < 97) || s[right] > 122;)
        {
            if((right-1) > 0){
                right--;
            }
        }
        if ((s[left]> 90 ? s[left]-32: s[left]) != (s[right]> 90 ? s[right]-32: s[right]))
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}
int main()
{
    cout<<tocheck()<<endl;
}