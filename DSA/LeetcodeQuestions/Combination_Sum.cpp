#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationgenerator(vector<int> &arr, vector<vector<int>> &res, std::vector<int> &subarr, int n, int target, int commutativesum, int start)
{
    if (commutativesum > target)
    {
        return;
    }
    else if (subarr.size() != 0 && commutativesum == target)
    {
        res.push_back(subarr);
    }
    else
    {
        for (int i = start; i < n; i++)
        {
            subarr.push_back(arr[i]);
            combinationgenerator(arr, res, subarr, n, target, commutativesum + arr[i], i);
            subarr.pop_back();
        }
    }
}

int main()
{

    vector<int> candidates{2, 3, 5};
    int target = 8;

    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> subarr;
    combinationgenerator(candidates, res, subarr, candidates.size(), target, 0, 0);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}