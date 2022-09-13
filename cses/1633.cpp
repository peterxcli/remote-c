#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

#define MAXN 1000005

int dp[MAXN];

const int mod = 1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // for (int i = 1; i <= 6; i++) dp[0][i] = 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j < 0) continue;
            dp[i] = (dp[i] + dp[i-j]) % mod;

        }
    }
    cout << dp[n] << "\n";
    return 0;
    // nlogn
    // len >= K   (N/k)^2 * k * nlogn
    // len < K
}