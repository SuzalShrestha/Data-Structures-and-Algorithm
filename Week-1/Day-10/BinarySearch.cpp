#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Binary Search
// Time Complexity: O(log(n))
// Space Complexity: O(n)
// Search the target element in the sorted array
// Array should be sorted
int Search(vector<int> a, int low, int high, int target)
{
    if (high < low) // Base case
        return low - 1;

    int mid = low + floor((high - low) / 2); // Find the middle element
    if (target == a[mid])
    {
        return mid;
    }
    else if (target > a[mid]) // If target is greater than middle element
    {
        return Search(a, mid + 1, high, target); // Search in the right half
    }
    else
    {
        return Search(a, low, mid - 1, target); // Search in the left half
    }
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int result = Search(numbers, 0, n - 1, target);
    if (result == -1)
    {
        cout << "result not present" << endl;
    }
    else
    {
        cout << "result found at index " << result << endl;
    }
    return result;
}