#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int rodCutting(const vector<int>& prices, int n) {
    // Create a DP array to store the maximum revenue obtainable for each length
    vector<int> dp(n + 1, 0);

    // Fill the DP array
    for (int i = 1; i <= n; i++) {
        int max_val = 0;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, prices[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }
      
    // The maximum revenue obtainable for length n is stored in dp[n]
    return dp[n];
}

int main() {
    vector<int> prices = {2,5,7,8};
    
    int n;
    cin>>n;

    int maxRevenue = rodCutting(prices, n);
    cout << "Maximum revenue obtainable: " << maxRevenue << endl;

    return 0;
}
