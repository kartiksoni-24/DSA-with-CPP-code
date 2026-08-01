#include<iostream>
using namespace std;

int reverseInt(int n){
    int reverseNum=0;
    while(n > 0){
        int lastDigit = n % 10;
        reverseNum = reverseNum * 10 + lastDigit; 
        n/=10;
    }
    return reverseNum;
}

int main(){

    cout<< reverseInt(125);
    return 0;
}
