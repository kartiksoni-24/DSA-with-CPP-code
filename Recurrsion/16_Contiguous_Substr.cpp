#include<iostream>
#include<string>
using namespace std;

// find the count of all contiguous substrings starting and ending with the same character
int substrCount(string str, int i, int j, int count){

    if (i == str.length())
    {
        // cout << substr << endl;
        return count;
    }
    if (j == str.length())
    {
        return substrCount(str, i + 1, i+1, count);
    }
    string substr = str.substr(i, j-i+1);

     if(substr[0] == substr[substr.length() - 1]){
        count++;
        cout << substr << endl;
     }
     return substrCount(str, i, j+1, count);

     
}

int main(){
    string str = "abcab";
    cout << substrCount(str, 0, 0, 0);
    return 0;
}