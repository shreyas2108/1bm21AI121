#include <iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n+1][capacity+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], values[n];
    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int max_value = knapsack(weights, values, n, capacity);
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
