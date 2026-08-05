#include<iostream>
using namespace std;

int countOccurance(int arr[], int si, int ei, int candidate){
    int count=0;
    for(int i =si; i <= ei; i++){
        if(arr[i] == candidate){
            count += 1;
        }
    }
    return count;
}

int findMajorityElement(int arr[], int si, int ei){
    if(si >= ei){
        return arr[si];
    }
    int mid = si+(ei-si)/2;

    int leftCandidate = findMajorityElement(arr, si, mid);
    int rightCandidate = findMajorityElement(arr, mid+1, ei);

    if(leftCandidate == rightCandidate){
        return leftCandidate;
    }
    int leftCandidateCount = countOccurance(arr, si,ei, leftCandidate);
    int rightCandidateCount = countOccurance(arr, si,ei, rightCandidate);

    if(leftCandidateCount > rightCandidateCount){
        return leftCandidate;
    } else{
        return rightCandidate;
    }
}

int main(){
    int arr[] = {2, 2, 3, 2, 3, 3, 3, 3};
    int n = sizeof(arr)/ sizeof(int);

    cout << findMajorityElement(arr, 0, n-1);
}