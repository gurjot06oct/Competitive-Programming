#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool almostequal(int x, int y)
    {
        string s1 = to_string(x), s2 = to_string(y);
        int n = s1.length(), m = s2.length();
        int maxLen = max(n, m);
        while (n != maxLen)
        {
            s1 = "0" + s1;
            n++;
        }
        while (m != maxLen)
        {
            s2 = "0" + s2;
            m++;
        }
        int diff = 0;

        unordered_map<int, int> um1, um2;
        for (int i = 0; i < 6; i++)
        {
            diff += s1[i] != s2[i];
            um1[s1[i]]++;
            um2[s2[i]]++;
        }
        return diff <= 2 && um1 == um2;
    }
    int countPairs(vector<int> &nums)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int size = nums.size(), count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                count += almostequal(nums[i], nums[j]);
            }
        }
        return count;
    }
};
int main()
{
    Solution a;
    vector<int> nums{1, 1, 1, 1, 1};
    cout << a.countPairs(nums) << endl;
}