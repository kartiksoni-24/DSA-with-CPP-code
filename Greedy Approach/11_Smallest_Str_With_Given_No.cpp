#include<iostream>
#include<string>
using namespace std;

string smallestStr(int n, int k){
    string str(n, 'a');
    int remaining = k -n;

    for (int i = n-1; i >= 0; i--)
    {
        int add = min(25, remaining);
        str[i] += add;
        remaining -= add;
    }
    return str;
}

int main(){
    cout << smallestStr(5, 73);
    return 0;
}