//https://codeforces.com/problemset/problem/431/C
#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;

int32_t main() {
    int n, k, d;
    cin >> n >> k >> d;
    int dp[105][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1, dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i < j) break;
            if (j < d) {
                dp[i][0] += dp[i-j][0], dp[i][0] %= mod;
                dp[i][1] += dp[i-j][1], dp[i][1] %= mod;
            }
            else {
                dp[i][1] += dp[i-j][0], dp[i][1] %= mod;
                dp[i][1] += dp[i-j][1], dp[i][1] %= mod;
            }
        }
    }
    cout << dp[n][1] << endl;
}