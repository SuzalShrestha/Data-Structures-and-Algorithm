#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int bestItem(int size, vector<int> weights, vector<int> values)
{
    int best_index = 0;
    double best = 0;
    double ratioVperW = 0;
    for (int i = 0; i < size; i++)
    {
        if (weights[i] > 0)
        {
            ratioVperW = static_cast<double>(values[i] / weights[i]);
            if (ratioVperW > best)
            {
                best = ratioVperW;
                best_index = i;
            }
        }
    }
    return best_index;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    int n = weights.size();
    vector<int> amounts(n);
    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            return value;
        }
        int best = bestItem(n, weights, values);
        float quantity = min(capacity, weights[best]);
        value = value + quantity * (static_cast<double>(values[best] / weights[best]));
        weights[best] = weights[best] - quantity;
        amounts[best] = amounts[best] + quantity;
        capacity = capacity - quantity;
    }

    return value;
}

int main()
{
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    std::cout << n << endl;
    std::cout << capacity << endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
