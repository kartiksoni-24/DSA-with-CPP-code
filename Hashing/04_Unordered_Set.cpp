#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main(){
    unordered_set<int> s;
    
    s.insert(23);
    s.insert(2);
    s.insert(3);
    s.insert(13);
    s.insert(22);
    s.insert(24);

    if(s.find(25) != s.end()){
        cout << "found\n";
    } else{
        cout << "not found\n";
    }

    cout << "Size of unordered set is : " << s.size() << endl;

    s.erase(13);
    for(auto &i : s){
        cout << i << endl;
    }

    return 0;
}