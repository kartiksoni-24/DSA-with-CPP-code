#include<iostream>
#include<string>
using namespace std;

string largestOddNo(string str){
    for (int i = str.size()-1; i >=0; i--)
    {
        int num = str[i] - '0';
        if(num % 2 != 0){
            return str;
        } else{
            str.pop_back();
        }
    }
    return "No odd number";
}

int main(){
    string str = "35427";
    cout << largestOddNo(str);
    return 0;
}