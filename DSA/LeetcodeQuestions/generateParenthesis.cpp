#include <bits/stdc++.h>
#include <vector>
using namespace std;

void genrateprans(int n, int left, int right, string &current, vector<string> &result)
{
    if (right == n)
    {
        result.push_back(current);
        return;
    }
    else
    {
        if (left < n)
        {
            current.push_back('(');
            genrateprans(n, left + 1, right, current, result);
            current.pop_back();
        }
        if (left > right)
        {
            current.push_back(')');
            genrateprans(n, left, right + 1, current, result);
            current.pop_back();
        }
    }
}

int main()
{
    string current = "";
    vector<string> ans;
    genrateprans(3, 0, 0, current, ans);
    return 0;
}
