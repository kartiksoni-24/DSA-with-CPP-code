#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<double, int> p1, pair<double, int> p2)
{
    return p1 > p2;
}

double fractionalKnapsack(vector<int> val, vector<int> wt, int W) // O(nlogn)
{
    int n = val.size();
    double ans = 0.0;
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0));

    for (int i = 0; i < n; i++)
    {
        ratio[i] = make_pair((val[i] / (double)wt[i]), i);
    }

    sort(ratio.begin(), ratio.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        int idx = ratio[i].second;
        if (wt[idx] <= W)
        {
            ans += val[idx];
            W -= wt[idx];
        }
        else
        {
            ans += (ratio[i].first * W);
            W = 0;
            break;
        }
    }

    return ans;
}

int main()
{
    vector<int> val = {10, 10, 10, 100};
    vector<int> wt = {10, 10, 10, 30};
    int W = 30;

    cout << "Max Value : " << fractionalKnapsack(val, wt, W);
    return 0;
}