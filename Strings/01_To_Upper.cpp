#include <iostream>
#include <string.h>
using namespace std;

void toUpper(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = arr[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            continue;
        }
        else
        {
            arr[i] = ch - 'a' + 'A';
        }
    }
}

int main()
{
    char word[] = "racecar";

    toUpper(word, strlen(word));
    cout << word;
}
