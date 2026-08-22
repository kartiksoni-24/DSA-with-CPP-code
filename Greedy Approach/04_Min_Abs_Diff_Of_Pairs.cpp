#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minAbsDiffPair(vector<int> A, vector<int> B){ // O(nlogn)
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;
    for (int i = 0; i < A.size(); i++)
    {
        absDiff += abs(A[i] - B[i]);
    }

    return absDiff;
}

int main(){
    vector<int> A = {4, 1,8,7};
    vector<int> B = {2,3,6,5};

    cout << "Min absolute diffrence : " << minAbsDiffPair(A, B);
    return 0;
}