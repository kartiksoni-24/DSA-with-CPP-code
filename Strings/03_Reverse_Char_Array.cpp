#include <iostream>
#include <string.h>
using namespace std;

void reverseArr(char arr[], int n)
{
    int st = 0, end = n - 1;

    while (st < end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

int main()
{
    char word[] = "racecar";

    reverseArr(word, strlen(word));
    cout << word;
}
