#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int largestSumSplit(vector<int>& vec, int k)
{
    int largest = INT_MIN;
    int sum = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > largest)
        {
            largest = vec[i];
        }
        sum += vec[i];
    }

    int answer = 0;

    while (largest <= sum)
    {
        // int mid = (largest + sum) / 2;
        int mid = largest + (sum - largest) / 2;
        int currSum = 0;
        int subarrays = 1;
        for (int i = 0; i < vec.size(); i++)
        {
            if ((currSum + vec[i]) <= mid)
            {
                currSum += vec[i];
            }
            else
            {
                currSum = vec[i];
                subarrays++;
            }
        }

        if (subarrays > k)
        {
            largest = mid +1;
        }
        else
        {
            answer = mid;
            sum = mid-1;
        }
        
    }
    return answer;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << largestSumSplit(vec, 2);
    return 0;
}