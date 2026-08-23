#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job
{
public:
    int idx, deadline, profit;

    Job(int idx, int deadline, int profit)
    {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs)
{
    int n = pairs.size();
    vector<Job> jobs;

    for (int i = 0; i < n; i++)
    {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b)
         { return a.profit > b.profit; });

    cout << "Selecting Job" << jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int nextDeadline = 2;

    for (int i = 1; i < jobs.size(); i++)
    {
        if (jobs[i].deadline >= nextDeadline)
        {
            cout << "Selecting Job" << jobs[i].idx << endl;
            profit += jobs[i].profit;
            nextDeadline++;
        }
    }
    return profit;
}

int main()
{
    vector<pair<int, int>> pairs = {{1, 10},
                                    {4, 20},
                                    {1, 40},
                                    {1, 30}};

    cout << "Max profit : " << maxProfit(pairs);
    return 0;
}