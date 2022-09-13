// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[200005], b[200005], vis[200005], onstk[200005];
vector<int> G[200005];
bool f;

void dfs(int u){
    onstk[u] = vis[u] = true;
    for (auto v : G[u]){
        if (onstk[v]) f = true;
        if (!vis[v]) dfs(v);
    }
    onstk[u] = false;
}

void solve_subtask() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i <= n; i++) G[i].clear(), vis[i] = 0;
    for (int i = 0; i < n; i++) G[a[i]].emplace_back(b[i]);
    int mx = 1;
	for(int i = 1; i <= n; i++) if (G[i].size() > G[mx].size()) mx = i;
    vis[mx] = true;
    f = false;
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);

    cout << (f ? "WA\n" : "AC\n");
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