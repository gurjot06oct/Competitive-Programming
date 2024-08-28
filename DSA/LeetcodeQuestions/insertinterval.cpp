#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval)
    {
        int l = 0, size=intervals.size(),r = size - 1, mid, ans = -1;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (intervals[mid][0] >= newInterval[0] || intervals[mid][1] >= newInterval[0])
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        if(intervals[size-1][0] <= newInterval[0]){
                ans=
        }
        return;
    }
};
int main()
{
    Solution a;
    a.insert({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {12, 15});
}