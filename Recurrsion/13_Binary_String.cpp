#include<iostream>
using namespace std;

void binStr(int n, int lastplace, string ans){
    if(n == 0){
        cout << ans << endl;
        return;
    }

    if(lastplace != 1){
        binStr(n-1, 0, ans+'0');
        binStr(n-1, 1, ans+'1');
    } else{
        binStr(n - 1, 0, ans + '0');
    }
}

int main(){
    binStr(3, 0, "");
    return 0;
}