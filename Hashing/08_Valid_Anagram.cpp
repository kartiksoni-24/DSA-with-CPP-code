#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool isAnagram(string str1, string str2){ // O(n)
    if(str1.size() != str2.size()){
        return false;
    }

    unordered_map<char, int> m;

    for (int i = 0; i < str1.size(); i++)
    {
        if(m.count(str1[i])){
            m[str1[i]]++;
        } else{
            m[str1[i]] = 1;
        }
    }
    
    for (int i = 0; i < str2.size(); i++)
    {
        if(m.count(str2[i])){
            m[str2[i]]--;
        } else{
            m[str2[i]] = -1;
        }
    }
    
    for(auto &i : m){
        if(i.second != 0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "race";
    string s2 = "car";

    cout << (isAnagram(s1,s2) ? "valid anagram" : "invalid");
    return 0;
}