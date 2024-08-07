#include <iostream>
using namespace std;

int searchinsertion(int *nums, int target, int right)
{
    int left = 0,mid;
    int ans = right+1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }else{
            ans=mid;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 5, 5, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << searchinsertion(arr, 0, n - 1);
    return 0;
}
