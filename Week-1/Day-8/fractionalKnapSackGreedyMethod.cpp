#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Item
{
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;

    int n = weights.size();
    vector<Item> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(Item(values[i], weights[i]));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            return value;
        }
        if (arr[i].weight <= capacity)
        {
            capacity -= arr[i].weight;
            value += arr[i].profit;
        }
        else
        {
            value += arr[i].profit * ((double)capacity / arr[i].weight);
            break;
        }
    }

    return value;
}

int main()
{
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
