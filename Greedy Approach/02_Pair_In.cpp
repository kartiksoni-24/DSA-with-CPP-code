#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int main(){
    vector<pair<int, int>> pairs(4, make_pair(0, 0)); // intialise all pair with 0,0

    pairs[0] = make_pair(2,5);
    pairs[1] = make_pair(1,7);
    pairs[2] = make_pair(3,4);
    pairs[3] = make_pair(0,9);

    for (int i = 0; i < pairs.size(); i++)
    {
        cout << pairs[i].first << ", " << pairs[i].second << endl;
    }

    //sort based on second value
    sort(pairs.begin(), pairs.end(), cmp);

    cout << "----------------------\n";
    for (int i = 0; i < pairs.size(); i++)
    {
        cout << pairs[i].first << ", " << pairs[i].second << endl;
    }
    return 0;
}