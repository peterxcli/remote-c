#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 105
int ans = LLONG_MAX, vis[MAXN];
vector<pair<int, int>> G[MAXN];
void dfs(int start, int fa, int cost) {
    if (start == 1) {
        ans = min(ans, cost);
        return;
    }
    for (auto x : G[start]) {
        if (x.first == fa)
            continue;
        dfs(x.first, start, cost + x.second);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, 0});
        G[b].push_back({a, c});
    }
    dfs(G[1][0].first, 1, G[1][0].second);
    dfs(G[1][1].first, 1, G[1][1].second);

    cout << ans << "\n";
}