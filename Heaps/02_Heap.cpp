#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;

    void heapify(int i){
        if(i >= vec.size()){
            return;
        }

        int leftIdx = 2*i+1;
        int rightIdx = 2*i+2;
        int maxIdx = i;

        if(leftIdx < vec.size() && vec[leftIdx] > vec[maxIdx]){
            maxIdx = leftIdx;
        }

        if(rightIdx < vec.size() && vec[rightIdx] > vec[maxIdx]){
            maxIdx = rightIdx;
        }

        swap(vec[i], vec[maxIdx]);
        if(maxIdx != i){
            heapify(maxIdx);
        }
    }
public: 
    void push(int val){ // O(logn)
        vec.push_back(val);

        int x = vec.size()-1;
        int parIdx = (x-1)/2;

        while(parIdx >= 0 && vec[x] > vec[parIdx]){ // for max heap use this condition. And for min head change > to <.
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x-1)/2;
        }
    }

    void pop(){ // O(logn)
        swap(vec[0], vec[vec.size()-1]);

        vec.pop_back();

        heapify(0);
    }

    int top(){ // O(1)
        return vec[0];
    }

    bool empty(){ // O(1)
        return vec.size() == 0;
    }
};

int main(){
    Heap h;

    h.push(32);
    h.push(12);
    h.push(41);
    h.push(30);
    h.push(28);

    cout << h.top() << endl;
    h.pop();
    cout << h.top();

    return 0;
}