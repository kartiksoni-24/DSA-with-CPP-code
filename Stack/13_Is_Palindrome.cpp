#include<iostream>
#include<stack>
#include<list>
#include<iterator>
using namespace std;

bool isPalindrome( list<int>& ll){
    stack<int> s;
    
    list<int>::iterator itr;

    for(itr = ll.begin(); itr != ll.end(); itr++){
        s.push(*itr);
    }

    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        if(*itr != s.top()){
            return false;
        }
        s.pop();
    }

    return true;
}

int main(){
    list<int> ll = {1,2,2,1};
    cout << isPalindrome(ll) << endl;

    return 0;
}