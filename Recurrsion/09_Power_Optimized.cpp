#include <iostream>
#include<vector>
using namespace std;

// ------------------------------------------optimized-----------------------------------------------
int pow1(int x, int n){
    if(n ==0 ){
        return 1;
    }

    int halfSq = pow1(x, n/2);
    int sqHalfSq = halfSq * halfSq;

    if(n % 2 != 0){
        return x * sqHalfSq;
    }
    return sqHalfSq;
}

int main()
{
    cout << pow1(2,5);
    return 0;
}
