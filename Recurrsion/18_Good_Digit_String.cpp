#include<iostream>
using namespace std;

int M = 1e9 +7;
int findPow(long long x, long long n){
    if(n == 0){
        return 1;
    }

    long long halfSq = findPow(x, n/2);
    long long ans = (halfSq * halfSq) %M;

    if(n %2 != 0){
        return (ans * x) % M;
    }

    return ans;
}

long long goodDigitStr(long long n){
    return (long long)findPow(5, (n+1)/2) * findPow(4, n/2);
}

int main(){
    cout << goodDigitStr(3);
    return 0;
}