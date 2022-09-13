#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 200005
vector<int> G[MAXN], ans_com, tmp;
int n, m;
int ans = LLONG_MAX, vis[MAXN], from[MAXN];

void bfs() {
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            from[v] = u;
            q.push(v);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bfs();
    if (!vis[n]) cout << "IMPOSSIBLE\n";
    else {
        stack<int> stk;
        stk.emplace(n);
        while (stk.top() != 1) {
            stk.emplace(from[stk.top()]);
        }
        cout << stk.size() << "\n";
        while (!stk.empty()) {
            cout << stk.top() << " "; stk.pop();
        }
        cout << "\n";
    }
    return 0;
}