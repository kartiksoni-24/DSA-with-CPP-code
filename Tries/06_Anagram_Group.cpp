#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<string>> anagramGroup(vector<string>& words){
    unordered_map<string, vector<string>> m;
    vector<vector<string>> ans;

    for (int i = 0; i < words.size(); i++)
    {
        string sortedStr = words[i];
        sort(sortedStr.begin(), sortedStr.end());
        m[sortedStr].push_back(words[i]);
    }
    
    for(auto &i : m){
        ans.push_back(i.second);
    }

    return ans;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> ans = anagramGroup(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}