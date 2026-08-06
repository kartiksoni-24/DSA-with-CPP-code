#include<iostream>
using namespace std;

void printSubstr(string str,string substr){
    if(str.size() == 0){
        cout << "[" << substr <<  "]";
        return;
    }

    char ch = str[0];

    printSubstr(str.substr(1, str.size()-1), substr+ch);//yes
    printSubstr(str.substr(1, str.size()-1), substr); //no
}

int main(){
    string str = "abc";
    printSubstr(str, " ");
}