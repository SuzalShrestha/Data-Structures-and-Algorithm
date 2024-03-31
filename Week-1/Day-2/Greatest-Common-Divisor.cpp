#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// using std::vector;
// Question: Find the Greatest Common Divisor of two numbers.
// Input : Two integers a and b.
// Output : Greatest Common Divisor of a and b.
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

// #include <vector>
// LeetCode Solution
// Optimal Solution on speed
//  Approach: Find the minimum and maximum of the array and find the GCD of the two numbers.
//  Time Complexity: O(n)
//  Space Complexity: O(1)
// int findMin(std::vector<int> a)
// {
//     int m = a[0];
//     for (auto i : a)
//     {
//         m = std::min(m, i);
//     }
//     return m;
// }
// int findMax(vector<int> a)
// {
//     int m = a[0];
//     for (auto i : a)
//     {
//         m = max(m, i);
//     }
//     return m;
// }
// int GCD(int a, int b)
// {
//     while (a != b)
//     {
//         if (a > b)
//             a -= b;
//         else
//             b -= a;
//     }
//     return a;
// }
// int findGCD(vector<int> &nums)
// {
//     int mi = findMin(nums);
//     int ma = findMax(nums);
//     return GCD(mi, ma);
// }

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCDfast(a, b) << endl;
    return 0;
}