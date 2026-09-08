#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void getUnion(vector<int>& vec1, vector<int>& vec2){
    unordered_set<int> s;

    for (int i = 0; i < vec1.size(); i++)
    {
        s.insert(vec1[i]);
    }
    for (int i = 0; i < vec2.size(); i++)
    {
        s.insert(vec2[i]);
    }
 
    cout << "Union : ";
    for(auto &i : s){
        cout << i << " ";
    }
}

void getIntersection(vector<int> &vec1, vector<int>& vec2){
    unordered_set<int> s;

    for (int i = 0; i < vec1.size(); i++)
    {
        s.insert(vec1[i]);
    }
    
    cout << "Intersection : " ;
    for(int i = 0 ; i < vec2.size(); i++){
        if(s.find(vec2[i]) != s.end()){
            cout << vec2[i] << " ";
            s.erase(vec2[i]);
        }
    }
}

int main(){
    vector<int> vec1 = {7,5,3};
    vector<int> vec2 = {2,4,1,7,5,2,4};

    getUnion(vec1, vec2);
    cout << endl;
    getIntersection(vec1, vec2);
    return 0;
}