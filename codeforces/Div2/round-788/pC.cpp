// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[100005], b[100005], d[100005], f[200005], cnt[200005], sz[200005];
const int mod = 1e9+7;

int findf(int x) {
    if (x == f[x]) return x;
    else return f[x] = findf(f[x]);
}

void Union(int a, int b) {
    a = findf(a), b = findf(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    f[b] = a;
    sz[a] += sz[b];
    sz[b] = 0;
}

void solve_subtask() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i <= n; i++) f[i] = i, cnt[i] = 0, sz[i] = 1;
    int ans = 1;
    for (int i = 0; i < n; i++) Union(a[i], b[i]);
    for (int i = 1; i <= n; i++) if (sz[i] > 1) cnt[i] = 1;
    for (int i = 0; i < n; i++) if (d[i] > 0) cnt[findf(d[i])] = 0;
    for (int i = 1; i <= n; i++) if (cnt[i]) ans = ans * 2 % mod;
    cout << ans << "\n";
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