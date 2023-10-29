#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for an item which stores profit and weight of the item
struct Item {
    int profit, weight;

    // Constructor
    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

// Comparison function to sort items based on the profit/weight ratio
bool cmp(const Item& a, const Item& b) {
    double r1 = static_cast<double>(a.profit) / a.weight;
    double r2 = static_cast<double>(b.profit) / b.weight;
    return r1 > r2;
}

// Main greedy function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double finalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
    const Item& item = items[i];
    if (item.weight <= W) {
        W -= item.weight;
        finalValue += item.profit;
    } else {
        finalValue += item.profit * (static_cast<double>(W) / item.weight);
        break;
    }
}


    return finalValue;
}

int main() {
    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    int N;
    cout << "Enter the number of items: ";
    cin >> N;

    vector<Item> items;
    for (int i = 0; i < N; i++) {
        int profit, weight;
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> profit >> weight;
        items.push_back(Item(profit, weight));
    }

    double result = fractionalKnapsack(W, items);

    cout << "Maximum profit that can be obtained: " << result << endl;

    return 0;
}

