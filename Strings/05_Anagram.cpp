#include <iostream>
// #include<string.h>
using namespace std;

void isAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        cout << "length is not equal!";
        return;
    }

    int count[26];
    for (int i = 0; i < str1.length(); i++)
    {
        count[str1[i] - 'a']++;
    }

    for (int i = 0; i < str1.length(); i++)
    {
        if (count[str2[i] - 'a'] == 0)
        {
            cout << "Not an anagram";
            return;
        }
        else
        {
            count[str2[i] - 'a']--;
        }
    }
    cout << "Anagram";
}

int main()
{
    string str1 = "race";
    string str2 = "care";

    isAnagram(str1, str2);

    return 0;
}
