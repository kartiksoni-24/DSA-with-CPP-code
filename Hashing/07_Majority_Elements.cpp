#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void majorityElements(vector<int> &vec) // O(n)
{
    int n = vec.size();
    unordered_map<int, int> m; // element, count/freq

    for (int i = 0; i < n; i++)
    {
        if (m.count(vec[i]))
        {
            int freq = m[vec[i]];
            m[vec[i]] = freq + 1; // or m[vec[i]]++
        }
        else
        {
            m[vec[i]] = 1;
        }
    }

    for (auto &i : m)
    {
        if (i.second > n / 3)
        {
            cout << i.first << " ";
        }
    }
}

int main()
{
    vector<int> vec = {1,2};
    majorityElements(vec);

    return 0;
}