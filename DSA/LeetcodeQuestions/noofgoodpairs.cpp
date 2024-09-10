#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int* dp =new int[n] { 1 };
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
int main()
{
    Solution a;
    int res = a.uniquePaths(3,4);
    cout << res << endl;
}