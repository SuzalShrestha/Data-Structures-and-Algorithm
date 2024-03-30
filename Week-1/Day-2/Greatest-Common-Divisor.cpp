#include <iostream>
using namespace std;
int GCD(int a, int b) // Native Solution
{
    // Time Complexity: O(a+b)
    // Space Complexity: O(1)
    int gcd = 0;
    for (int i = 1; i < a + b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}
int GCDfast(int a, int b) // Optimized Solution from property of GCD also called Euclidean Algorithm
// Euclidean Algorithm
// Time Complexity: O(log(min(a,b)))
// Space Complexity: O(1)
{
    if (b == 0)
    {
        return a;
    }
    // property of GCD : gcd(a,b) = gcd(b,a%b) until a%b = 0
    return GCDfast(b, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCDfast(a, b) << endl;
    return 0;
}