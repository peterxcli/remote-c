#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
double dp[3005][3005];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<double> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    dp[1][0] = 1 - p[1];
    dp[1][1] = p[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = dp[i-1][j] * (1 - p[i]);
            else dp[i][j] = dp[i-1][j] * (1 - p[i]) + dp[i-1][j-1] * p[i];
        }
    }
    double ans = 0;
    for (int i = (n / 2) + 1; i <= n; i++) ans += dp[n][i];
    cout << setprecision(12) << ans << "\n";
    return 0;
}