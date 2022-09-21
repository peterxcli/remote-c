//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
#define MAXN 100005
int remainer[MAXN];
void solve_subtask() {
    memset(remainer, 0, sizeof remainer);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) remainer[a[i]%m]++;
    int ans = 0;
    int cur;
    if (remainer[0]) ans++;
    for (int i = 1; i < m;) {
        // // cout << i << "\n";
        // if (remainer[i]) {
        //     cur = i;
        //     remainer[i]--;
        //     ans++;
        // }
        // else {
        //     i++;
        //     continue;
        // };
        // while (remainer[m-cur]) {
        //     cur = m-cur;
        //     remainer[cur]--;
        // }
        if (2 * i <= m) {
            int x = remainer[i], y = remainer[m-i];
            if (x == y && x == 0) continue;
            ans += 1 + max((int64_t)0, abs(x - y) - 1);
        }
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}
