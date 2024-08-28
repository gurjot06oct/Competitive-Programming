#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t1 = 0, t2 = 0, t3 = 0;
    for (char c : s)
    {
        if (c == ')')
        {
            if (t2 == 0 && t3 == 0)
            {
                t1--;
            }
            else
            {
                return false;
            }
        }
        else if (c == '(')
        {
            t1++;
        }
        if (c == '}')
        {
            if (t1 == 0 && t3 == 0)
            {
                t2--;
            }
            else
            {
                return false;
            }
        }
        else if (c == '{')
        {
            t2++;
        }
        if (c == ']')
        {
            if (t2 == 0 && t1 == 0)
            {
                t3--;
            }
            else
            {
                return false;
            }
        }
        else if (c == '[')
        {
            t3++;
        }
        if (t1 < 0 || t2 < 0 || t3 < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << tocheck() << endl;
}