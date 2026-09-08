#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

void printItinerary(unordered_map<string, string> m)
{
    unordered_set<string> dest;

    for (auto &i : m)
    {
        dest.insert(i.second);
    }

    string start = "";
    for (auto &i : m)
    {
        if (dest.find(i.first) == dest.end())
        {
            start = i.first;
        }
    }

    cout << start << " -> ";
    while (m.count(start))
    {
        cout << m[start] << " -> ";
        start = m[start];
    }
    cout << "Finish";
}

int main()
{
    unordered_map<string, string> m = {{"chennai", "bengaluru"}, {"mumbai", "delhi"}, {"delhi", "goa"}, {"goa", "chennai"}};

    printItinerary(m);
    return 0;
}