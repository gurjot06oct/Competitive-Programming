#include <iostream>
#include <vector>
using namespace std;

int findLastOccurrence(const vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}
int main()
{
    vector<int> testCase = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = testCase.size();
    int ind = n / 2;
    int l = ind, r = n - 1;
    int lastone = findLastOccurrence(testCase, testCase[ind]);
    cout << (lastone >= ind && testCase[lastone] == testCase[lastone - ind]) << endl;
    return 0;
}
