#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) 
{ 
return (a > b) ? a : b; 
}

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> profit(n), weight(n);
    cout << "Enter the profits and weights of items:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (profit weight): ";
        cin >> profit[i] >> weight[i];
    }

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    int result = knapSack(W, weight, profit, n);
    cout << "Maximum profit is: " << result << endl;

    return 0;
}

