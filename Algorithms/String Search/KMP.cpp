#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
void computePrefixFunction(string pattern, vector<int> &pi)
{
    int m = pattern.size();
    pi[0] = 0; // the first element is always 0
    int j = 0; // length of previous longest prefix suffix

    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        pi[i] = j;
    }
}
void KMPsearch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> pi(m);
    computePrefixFunction(pattern, pi);

    int j = 0; // index for pattern

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << (i - m + 1) << endl;
            j = pi[j - 1];
        }
    }
}

int main()
{
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    KMPsearch(text, pattern);

    return 0;
}
