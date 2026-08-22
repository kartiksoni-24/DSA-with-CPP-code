#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);

    int profit = jobs[0].second;
    int nextDeadline = 2;

    for (int i = 1; i < jobs.size(); i++)
    {
        if (jobs[i].first >= nextDeadline)
        {
            profit += jobs[i].second;
            nextDeadline++;
        }
    }
    return profit;
}

int main()
{
    int n = 4;
    vector<pair<int, int>> jobs = {
        {1, 10},
        {4, 20},
        {1, 40},
        {1, 30}};

    cout << maxProfit(jobs);
    return 0;
}