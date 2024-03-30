#include <iostream>
using namespace std;
// Question: Find the nth Fibonacci number.
// Input : An integer n.
// Output : The nth Fibonacci number.
int fibonacci(int n) // native resursive solution
{
    // Time Complexity: O(2^n)
    // Space Complexity: O(n)
    if (n <= 1)
    {
        return n;
    }
    else
    {
        // it is very slow and inefficient because it calculates the same value multiple times.
        // eg. fibonacci(5) = fibonacci(4) + fibonacci(3)
        // fibonacci(4) = fibonacci(3) + fibonacci(2)
        // fibonacci(3) = fibonacci(2) + fibonacci(1)
        // fibonacci 3 and fibonacci 2 are calculated multiple times separately.
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
long fibonacciFast(int n) // optimized solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    if (n <= 1)
    {
        return n;
    }
    long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        // adds the previous two numbers to get the next number and avoids calculating the same value multiple times.
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
int fibonacciFastest(int n) // optimal solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    if (n <= 1)
    {
        return n;
    }
    long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) // eliminates the need for an array to store the values which is O(n) space complexity.
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    int n;
    cin >> n;
    cout << fibonacciFast(n) << endl;
    return 0;
}