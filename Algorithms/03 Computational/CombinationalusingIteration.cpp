#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Combinations(const vector<vector<int>> &digits)
{
    long total=1;
    int n=digits.size();
    for (int i = 0; i < n; i++) total*=digits[i].size();
    vector<vector<int>> res(total,vector<int>(n,0));
    int iterat=1;
    for (int i = n-1; i>=0; i--)
    {
        total/=digits[i].size();
        int k=0;
        for (int j = 0; j < total; j++)
        {
            for (int l = 0; l < digits[i].size(); l++)
            {
                for (int m = 0; m < iterat; m++)
                {
                    res[k++][i]=digits[i][l];
                }
            }
        }
        iterat*=digits[i].size();
    }
    return res;
}
int main()
{
    vector<vector<int>> res = Combinations({{0,1},{0,1,2},{1,4,2,3}});
    for (auto it : res)
    {
        for (auto it2 : it)
        {
            cout << it2 <<" ";
        }
        cout<<endl;
    }
}