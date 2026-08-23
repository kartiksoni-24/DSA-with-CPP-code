#include<iostream>
#include<string>
using namespace std;

int maxBalancedStr(string str){
    int balance = 0;
    int ans = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'L'){
            balance++;
        } else{
            balance--;
        }

        if(balance == 0){
            ans++;
        }
    }
    return ans;
}

int main(){
    string str = "RLRRRLLRLL";
    cout << maxBalancedStr(str);
    return 0;
}