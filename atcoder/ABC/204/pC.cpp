#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
#define MAXN 2005
vector<int> G[MAXN];
int vis[MAXN], ans;
void dfs(int start, int v) {
    vis[v] = true;
    ans++;
    for (auto u : G[v]) {
        if (vis[u]) continue;
        dfs(start, u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        G[x].emplace_back(y);
    }
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof vis);
        dfs(i, i);
    }
    cout << ans << "\n";
    return 0;
}