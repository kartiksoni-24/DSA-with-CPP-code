#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void areaOfHistogram(vector<int> height){ // O(n)
    int n = height.size();
    stack<int> s;
    vector<int> nsl(n);
    vector<int> nsr(n);

    //next smallest left
    nsl[0] = -1;
    s.push(0);
    for(int i = 1; i < n; i++){
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nsl[i] = -1;
        } else{
            nsl[i] = s.top();
        }

        s.push(i);
    }

    while (s.empty())
    {
        s.pop();
    }

    //next smallest right
    s.push(n - 1);
    nsr[n-1] = n;
    for(int i = n-2; i>=0; i--){
        int curr = height[i];
        while (!s.empty() && curr <= height[s.top()])
        {
            s.pop();
        }
        
        if(s.empty()){
            nsr[i] = n;
        } else{
            nsr[i] = s.top();
        }

        s.push(i);
    }

    // calculate max area 
    int maxArea = 0;
    for(int i =0; i<n; i++){
        int ht = height[i];
        int wd = nsr[i] - nsl[i] - 1;
        int area = ht * wd;

        maxArea = max(maxArea, area);
    }

    cout << "Max area of histogram : " << maxArea <<endl;
}

int main(){
    vector<int> hieght = {2,1,5,6,2,3};
    areaOfHistogram(hieght);

    return 0;
}