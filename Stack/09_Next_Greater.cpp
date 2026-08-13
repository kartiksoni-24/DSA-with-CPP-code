#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreater(vector<int>& arr, vector<int>& ans){
    stack<int> s;

    for (int i = arr.size()-1; i >=0 ; i--)
    {
        int curr = arr[i];
        while(!s.empty() && curr >= s.top() ){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
            s.push(arr[i]);
        }  else{
            ans[i] = s.top();
            s.push(arr[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    vector<int> ans;
    ans.assign(arr.size(), 0);

    nextGreater(arr, ans);
    return 0;
    
}