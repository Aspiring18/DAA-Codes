#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
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

