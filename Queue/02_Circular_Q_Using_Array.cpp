#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int f, r;
    int currSize;
    int capacity;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        f = 0; 
        r = -1;
        currSize = 0;
    }

    void push(int val){
        if(currSize == capacity){
            cout << "queue is full\n";
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = val;
        currSize++;
    }
    void pop(){
        if(empty()){
            cout << "queue is empty\n";
            return ;
        }

        f = (f+1)%capacity;
        currSize--;
    }
    bool empty(){
        return currSize == 0;
    }
    int front(){
        return arr[f];
    }

    void printR(){
        cout << arr[r];
    }
};

int main(){
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    
    cout << q.front() << " ";
    q.pop();
    cout << q.front() << " ";
    q.push(6);
    q.printR();

}