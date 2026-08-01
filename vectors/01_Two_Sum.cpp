#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int st = 0, end = numbers.size() - 1;
    while (st < end)
    {
        vector<int> res;
        int currSum = numbers[st] + numbers[end];
        if (currSum == target)
        {
            res.push_back(st);
            res.push_back(end);
            return res;
        }
        else if (numbers[st] + numbers[end] > target)
        {
            end--;
        }
        else
        {
            st++;
        }
        return res;
    }
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    vector<int> ans = twoSum(arr, 9);
    cout << ans[0] << ", " << ans[1];
    return 0;
}
