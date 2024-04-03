#include <iostream>
#include <vector>
using namespace std;

// int maxCoins(vector<int> &coins, int amount)
// {
//     int max = 0;
//     int size = coins.size();
//     for (int i = 0; i < size; i++)
//     {
//         if (coins[i] > max && coins[i] <= amount)
//         {
//             max = coins[i];
//         }
//     }
//     return max;
// }
// int coinChange(vector<int> &coins, int amount)
// {
//     int numCoins = 0;
//     while (amount > 0)
//     {
//         int max = maxCoins(coins, amount);
//         if (amount - max < 0)
//         {
//             return -1;
//         }
//         amount = amount - max;
//         numCoins = numCoins + 1;
//     }
//     return numCoins;
// }
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
        for (const int coin : coins)
            if (coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}
int main()
{
    int amount, n;
    cin >> amount >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int result = coinChange(coins, amount);
    cout << result << endl;
    return result;
}