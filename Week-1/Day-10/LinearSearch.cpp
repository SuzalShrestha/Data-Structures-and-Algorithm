#include <iostream>
#include <vector>
using namespace std;
// Linear Search
// Time Complexity: O(n)
// Space Complexity: O(n)
// Search the target element in the array
// Array may or may not be sorted
int search(vector<int> a, int target)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target) // If target element is found
        {
            return i; // Return the index of the target element
        }
    }
    return -1;
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
    int result = search(numbers, target);
    if (result != -1)
    {
        cout << "Target found in index " << result << endl;
    }
    else
    {
        cout << "Target not found";
    }
    return result;
}