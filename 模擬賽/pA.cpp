#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
// #define int long long
#define MAXN 10000005
int n, m, q, ori[MAXN], ans[MAXN], vis[MAXN];
vector<int> G[MAXN];
void bfs() {
    queue<pair<int, int>> q; //u, order
    for (int i = 0; i < n; i++) {
        if (ori[i]) {
            q.push(make_pair(i, 0));
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int u = cur.first, order = cur.second;
        ans[u] = order;
        for (auto v : G[u]) {
            if (vis[v]) continue;
            q.push(make_pair(v, order+1));
            vis[v] = 1;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> ori[i];
        ans[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bfs();
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (ans[x] == -1) cout << "N\n";
        else cout << ans[x] << "\n";
    }
    return 0;
}