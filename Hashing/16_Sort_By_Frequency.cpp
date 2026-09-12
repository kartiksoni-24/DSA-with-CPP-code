#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2){
    return p1.second > p2.second;
}

void sortByFreq(string str){
    unordered_map<char, int> m;

    for (int i = 0; i < str.size(); i++)
    {
        if(m.count(str[i])){
            m[str[i]]++;
        } else{
            m[str[i]] = 1;
        }
    }

    vector<pair<char, int>> freq;
    
    for(auto &i : m){
        freq.push_back({i.first, i.second});
    }

    sort(freq.begin(), freq.end(), cmp);
    
    for (int i = 0; i < freq.size(); i++)
    {
        for(int j = 0; j< freq[i].second; j++){
            cout << freq[i].first;
        }
    }
    
}

int main(){
    string str = "cccaaa";
    sortByFreq(str);

    return 0;
}