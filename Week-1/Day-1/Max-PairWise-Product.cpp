#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
// Question: Find the maximum product of two distinct numbers in a sequence of non-negative integers.
// Input : First line contains an integer n. Second line contains n non-negative integers.
// Output : Maximum product of two distinct numbers in the sequence.
// long long MaxPairwiseProduct(const vector<int> &numbers) // Native Solution
// {
//     long long n = numbers.size();
//     long long result = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             long long product1 = ((long long)numbers[i]) * ((long long)numbers[j]);
//             if (product1 > result)
//             {
//                 result = product1;
//             }
//         }
//     }
//     return (long long)result;
// }
long long MaxPairwiseProductFast(const vector<int> &numbers) // Optimized Solution
{

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int n = numbers.size();
    int max_index1 = -1;
    for (int i = 0; i < n; i++)
    {
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
        {
            max_index1 = i;
        }
    }
    int max_index2 = -1;
    for (int i = 0; i < n; i++)
    {
        if ((i != max_index1) && ((max_index2 == -1) || (numbers[i] > numbers[max_index2])))
        {
            max_index2 = i;
        }
    }
    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}
// LeetCode Solution
// Approach: Sort the array and return the product of last two elements.
// Most optimal solution
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int maxProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return ((nums[nums.size() - 1]) * (nums[nums.size() - 2]));
}

int main()
{
    // stress testing
    // while (true)
    // {
    //     int n = rand() % 10 + 2; // Random number between 2 to 10
    //     vector<int> numbers(n);
    //     for (int i = 0; i < n; i++)
    //     {
    //         numbers[i] = rand() % 10;
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << numbers[i] << " ";
    //     }
    //     if (MaxPairwiseProductFast(numbers) != MaxPairwiseProduct(numbers))
    //     {
    //         cout << "Wrong Answer" << endl;
    //         break;
    //     }
    //     else
    //     {
    //         cout << "OK" << endl;
    //     }
    // }
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    // long long result = MaxPairwiseProduct(numbers);
    long long result1 = MaxPairwiseProductFast(numbers);
    cout << result1 << "\n";
    return 0;
}
