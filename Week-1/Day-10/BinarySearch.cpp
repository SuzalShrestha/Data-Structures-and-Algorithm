#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int Search(vector<int> a, int low, int high, int target)
{
    if (high < low)
        return low - 1;
    int mid = low + floor((high - low) / 2);
    if (target == a[mid])
    {
        return mid;
    }
    else if (target > a[mid])
    {
        return Search(a, mid + 1, high, target);
    }
    else
    {
        return Search(a, low, mid - 1, target);
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