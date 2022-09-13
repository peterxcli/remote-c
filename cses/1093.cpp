#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
const int mod = 1e9+7; 
int dp[505][150000];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int sum = n*(n+1) / 2;
    if (sum & 1) return cout << "0\n", 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum >> 1; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - i < 0) continue;
            if (dp[i-1][j-i]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % mod;
                
            }
        }
    }
    cout << dp[n][sum>>1] << "\n";
    return 0;
}