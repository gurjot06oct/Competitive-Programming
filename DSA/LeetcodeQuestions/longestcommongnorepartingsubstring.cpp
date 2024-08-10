#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
    string s = "pwwkew"; // abcabcbb
    if (s.length() == 0)
        return 0;
    unordered_map<char, int> mapped;
    int left = 0, max = 1;
    mapped[s[0]] = 0;
    for (int right = 1; right < s.length(); right++)
    {
        if (mapped.find(s[right]) == mapped.end())
        {
            mapped[s[right]] = -1;
        }
        if (mapped[s[right]] > -1)
        {
            for (int j = left; j < mapped[s[right]]; j++)
            {
                mapped[s[j]] = -1;
            }
            left = mapped[s[right]]+1;
        }
        mapped[s[right]] = right;
        if (max < (right - left + 1))
        {
            max = (right - left + 1);
        }
    }
    cout << max << endl;
}