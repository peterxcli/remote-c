#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
const int mod = 1e9+7;
int N, K, dp[105][100005], a[105];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    // dp[0][0] = 1;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 0; i <= a[1]; i++) dp[1][i] = 1;
    for (int i = 0; i <= N; i++) dp[i][0] = 1;
    for (int i = 1; i <= K; i++) dp[1][i] = (dp[1][i-1] + dp[1][i]) % mod;
    auto k = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = (j - a[i] - 1 >= 0 ? ((dp[i-1][j] - dp[i-1][j - a[i] - 1] + mod) % mod) : (dp[i-1][j] + mod) % mod);
        }
        for (int j = 1; j <= K; j++) dp[i][j] = (dp[i][j-1] + dp[i][j]) % mod;
        // for (int j = 1; j <= K; j++) dp[i][j] = dp[i-1][j];
    }
    cout << (dp[N][K] - dp[N][K-1] + mod) % mod << "\n";
    return 0;
}