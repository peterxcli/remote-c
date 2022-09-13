#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAXN 1005

const int mod = 1e9+7;

int H, W, dp[MAXN][MAXN];
char grid[MAXN][MAXN];

int32_t main() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        cin >> grid[i]+1;
    }
    for (int i = 1; i <= W; i++) if (grid[1][i] == '.') dp[1][i] = 1; else break;
    for (int i = 1; i <= H; i++) if (grid[i][1] == '.') dp[i][1] = 1; else break;
    for (int i = 2; i <= H; i++) {
        for (int j = 2; j <= W; j++) {
            if (grid[i][j] == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            else dp[i][j] = 0;
        }
    }
    cout << dp[H][W] << "\n";
}