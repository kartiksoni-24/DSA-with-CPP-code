// Problem:
// Find the binomial coefficient for n and r.
//
// Approach:
// Compute n!, r!, and (n-r)! and apply n! / (r! * (n-r)!).
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

int findFact(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}

int findBC(int n, int r)
{
    int factN = findFact(n);
    int factR = findFact(r);
    int factNR = findFact(n - r);

    double BC = factN / (factR * factNR);
    return BC;
}

int main()
{
    cout << "BC is : " << findBC(10, 5);
    return 0;
}
