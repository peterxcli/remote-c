#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int n, x[105] ,dp[105][100005];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100000; j++) {
            if (dp[i-1][j]) dp[i][j] = 1;
            if (j - x[i] < 0) continue;
            if (dp[i-1][j - x[i]]) dp[i][j] = 1;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= 100000; i++) if(dp[n][i]) ans.emplace_back(i);
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}