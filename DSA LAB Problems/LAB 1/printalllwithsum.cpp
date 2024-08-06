#include <iostream>
#include <vector>
using namespace std;
void printSub(int arr[], int index, std::vector<int> &subarr, int n, int sum)
{
    if (index == n)
    {
        int testsum = 0;
        for (auto it : subarr)
        {
            testsum += it;
        }
        if (subarr.size() != 0)
        {
            if (testsum == sum)
            {
                for (auto it : subarr)
                {
                    cout << it << " ";
                }
                cout << endl;
            }
        }
        return;
    }
    else
    {
        subarr.push_back(arr[index]);
        printSub(arr, index + 1, subarr, n, sum);
        subarr.pop_back();
        printSub(arr, index + 1, subarr, n, sum);
    }
}
int main()
{
    int n, sum;
    cin >> n;
    int *arr = new int[n]{};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter Sum of elements: ";
    cin >> sum;
    vector<int> vec;
    printSub(arr, 0, vec, n, sum);
    return 0;
}