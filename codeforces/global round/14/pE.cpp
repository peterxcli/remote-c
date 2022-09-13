//codeforces template
// #define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define MAXN 500
using namespace std;
int dp[MAXN][MAXN][2];
void solve_subtask() {
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof dp);
    // for (int i = 0; i <= n; i++) dp[1][i][1] = 1;
    dp[1][1][1] = 1; dp[1][0][0] = 1;
    // for (int i = 1; i <= n; i++) dp[i][1][0] = dp[i][1][1] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i+1][j+1][1] += dp[i][j][1];
            dp[i+1][j+1][1] %= m;
            dp[i+1][j][0] += dp[i][j][0] + dp[i][j][1];
            dp[i+1][j][0] %= m;
            dp[i+1][j][1] += dp[i][j][0];
            dp[i+1][j][1] %= m;
        }
    }
    cout << dp[n][n][1] << " " << dp[n][n][0] << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}