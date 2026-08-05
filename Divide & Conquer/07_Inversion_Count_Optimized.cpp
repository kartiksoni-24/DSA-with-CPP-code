#include <iostream>
#include <vector>
using namespace std;

int merge(int arr[], int si, int ei, int mid, int count)
{
    vector<int> vec;
    int i = si, j = mid + 1;

    while (i <= mid && j <= ei)
    {
        if (arr[j] < arr[i])
        {
            count += mid - i + 1;
            vec.push_back(arr[j]);
            j++;
        }
        else
        { // arr[i] < arr[j]
            vec.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        vec.push_back(arr[i++]);
    }
    while (j <= ei)
    {
        vec.push_back(arr[j++]);
    }
    for (int idx = si, x = 0; idx <= ei; idx++)
    {
        arr[idx] = vec[x++];
    }
    return count;
}

int divide(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return 0;
    }

    int mid = si + (ei - si) / 2;

    int leftHalf = divide(arr, si, mid);
    int rightHalf = divide(arr, mid + 1, ei);

    return leftHalf + rightHalf + merge(arr, si, ei, mid, 0);
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << "Inversion count : " << divide(arr, 0, n - 1);
}