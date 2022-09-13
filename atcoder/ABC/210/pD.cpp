#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 1005
const int inf = 1e18;
int A[MAXN][MAXN], dp[MAXN][MAXN], dp2[MAXN][MAXN];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W, C;
    cin >> H >> W >> C;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < MAXN; i++) dp[i][0] = dp[0][i] = inf;
    int ans = LLONG_MAX;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = min(dp[i-1][j] + C, min(dp[i][j-1] + C, A[i][j]));
            dp2[i][j] = min(dp[i-1][j], dp[i][j-1]) + C + A[i][j];
            ans = min(ans, dp2[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}