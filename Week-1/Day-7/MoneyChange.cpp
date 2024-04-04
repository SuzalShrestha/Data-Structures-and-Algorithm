#include <iostream>
#include <vector>
using namespace std;
// Money Change Problem
// Compute the min number of coins needed to change the given value into coins with denominations 1,5,10;
// Input:an integer money
// Output: The minimum number of coins with denominations 1,5,10 that changes money
int get_change(int money)
{
    // oneline solution
    // return [money/10]+[(money%10)/5]+(money %5)
    int numCoins = 0;
    while (money > 0)
    {
        if (money >= 10)
        {
            money = money - 10;
        }
        else if (money >= 5)
        {
            money = money - 5;
        }
        else
        {
            money = money - 1;
        }
        numCoins = numCoins + 1;
    }
    return numCoins;
}
int main()
{
    int money;
    cin >> money;
    cout << get_change(money) << '\n';
    // test case
    // input: 28
    // output: 6
    // 28 = 10 + 10 + 5 + 1 + 1 + 1
    return 0;
}