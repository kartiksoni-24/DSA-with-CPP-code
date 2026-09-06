#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car{
    public:
    int idx, distSq;

    Car(int idx, int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator < (const Car &obj) const{
        return this->distSq > obj.distSq; // min heap
    }
};

void kNearbyCar(vector<pair<int, int>> pos, int k){
    vector<Car> cars;

    for (int i = 0; i < pos.size(); i++) // O(n)
    {
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, distSq));
    }
    
    priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)

    for (int i = 0; i < k; i++) // O(k*logn + n)
    {
        cout << "car " << pq.top().idx << endl;
        pq.pop();
    }
}

int main(){
    vector<pair<int, int>> vec = {{3,3}, {5, -1}, {-2, 4}};
    int k = 1;

    kNearbyCar(vec, k);

    return 0;
}