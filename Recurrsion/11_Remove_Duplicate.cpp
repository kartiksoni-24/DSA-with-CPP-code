#include<iostream>
#include <string>
using namespace std;

// O(n^2)
string removeDuplicate(const string& str, int i, string& ans){

    if(i >= str.length()){
        return ans;
    }
   
    if(ans.find(str[i]) == string::npos){
        ans += str[i];
        return removeDuplicate(str, i + 1, ans);
    }

    return removeDuplicate(str, i + 1, ans);
}

void rmDuplicate(string str, string ans, int i, int map[26]){

    if(i == str.length()){
        cout << ans;
        return;
    }

    int mapIdx = (int)(str[i] - 'a');

    if(map[mapIdx]){
        rmDuplicate(str, ans, i+1, map);
    } else{
        map[mapIdx] = true;
        rmDuplicate(str, ans+str[i], i+1, map);
    }
}

int main(){
    string str = "kartiksoni";
    // cout << str.length() << " " << str[2];
    string ans = "";
    int map[26] = {false};
    rmDuplicate(str,ans, 0, map);

    return 0;
}