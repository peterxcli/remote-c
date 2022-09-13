//:https://codeforces.com/problemset/problem/1038/D
#include<bits/stdc++.h>
#define int long long
#define inf (int)1e18
using namespace std;

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a;
    vector<array<array<int, 2>, 2> > dp;
    a.resize(n), dp.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) return cout << a[0] << "\n", 0;
    dp[0][1][0] = a[0], dp[0][0][1] = -a[0];
    dp[0][0][0] = dp[0][1][1] = -inf;
    for (int i = 1; i < n; i++) {
        dp[i][1][0] = dp[i-1][1][0]+a[i];
        dp[i][0][1] = dp[i-1][0][1]-a[i];

        dp[i][1][1] = max(dp[i-1][0][1]+a[i], max(dp[i-1][1][0]-a[i], dp[i-1][1][1]+abs(a[i])));
    }
    cout << dp[n-1][1][1] << "\n";
}