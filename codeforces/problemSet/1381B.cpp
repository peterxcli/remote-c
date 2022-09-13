//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define MAXN 2005
#define endl '\n'
#define int long long
using namespace std;
int vis[MAXN], a[MAXN], dp[MAXN];
void solve_subtask() {
    int n;
    cin >> n;
    vector<int> p(2*n+1), ind, len;
    for (int i = 1; i <= 2*n; i++) cin >> p[i];

    int mx = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (p[i] > mx) {
            mx = p[i];
            ind.emplace_back(i);
        }
    }
    ind.emplace_back(2*n+1);
    for (int i = 1; i < ind.size(); i++) len.emplace_back(ind[i] - ind[i-1]);
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (auto x : len) {
        for (int i = n - x; i >= 0; i--) {
            if (dp[i]) dp[i+x] = 1;
        }
    }
    cout << (dp[n] ? "yes" : "no") << "\n";

    // sort(len.begin(), len.end());
    // memset(vis, 0, sizeof vis);
    // vis[0] = true;
    // int m = len.size();
    // for (int i = 0; i < m; i++) {
    //     int r = i;
    //     while (r < m && len[r] == len[i]) r++;
    //     memset(a, 0, sizeof a);
    //     for (int j = len[i]; j <= n; j++) {
    //         if (!vis[j] && vis[j-len[i]] && a[j - len[i]] < r - i) {
    //             a[j] = a[j-len[i]] + 1;
    //             vis[j] = true;;
    //         }
    //     }
    //     i = r-1;
    // }
    // cout << (vis[n] ? "YES\n" : "NO\n");
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