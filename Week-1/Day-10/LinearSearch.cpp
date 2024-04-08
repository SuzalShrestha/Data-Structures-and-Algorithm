#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> a, int target)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
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