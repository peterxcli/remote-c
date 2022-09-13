// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[200005], b[200005], cnt[200005];
vector<int> G[200005];
void solve_subtask() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) cnt[a[i]]++, b[i] = a[i];
    sort(b, b+n);
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, cnt[i]);
    for (int i = 0; i < n; i++) G[b[i]].emplace_back(b[(i + mx) % n]);
    for (int i = 0; i < n; i++) cout << G[a[i]].back() << (i == n-1 ? "\n" : " "), G[a[i]].pop_back();
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