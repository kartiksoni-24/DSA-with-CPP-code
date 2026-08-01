#include <iostream>
#include<vector>
using namespace std;

// ----------------------------Nth fibonacci no-------------------------------------
int findFibo(int n){
    if(n == 0 || n == 1){
        return n;
    }
    
    return findFibo(n-1) + findFibo(n-2);
}

int main()
{
    cout << findFibo(6);
    return 0;
}
