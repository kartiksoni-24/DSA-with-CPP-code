#include<iostream>
using namespace std;

int frndPair(int n){

    if(n == 1 || n ==2){
        return n;
    }

    return frndPair(n-1) + (n-1)*frndPair(n-2);
}

int main(){
    cout << frndPair(3);
}