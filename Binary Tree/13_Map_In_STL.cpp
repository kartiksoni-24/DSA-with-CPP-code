#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    map<int, string> m;

    m[01] = "kartik";
    m[02] = "soni";
    m[03] = "ji";

    cout << m[03] << endl;
    cout << m.count(04) << endl; // if the key present 1, if not 0

    for (auto &i : m)
    {
        cout << i.first << " = " << i.second+" lol" << endl;
    }
    return 0;
}