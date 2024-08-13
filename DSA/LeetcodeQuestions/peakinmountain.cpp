#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums{1, 2, 3, 4, 0};

    int ans, mid;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {

        if (nums[mid] < nums[mid + 1])
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << nums[mid] << endl;
    return nums[mid];
    return 0;
}
