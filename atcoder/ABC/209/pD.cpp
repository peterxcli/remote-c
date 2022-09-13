#include <bits/stdc++.h>
#define N 100005
#define LogN 20
using namespace std;

int n, m, depth[N], fa[N][LogN];
vector<int> tree[N];

int LCA_distance(int u, int v) {
    int ret = 0;
    if (depth[u] > depth[v]) swap(u, v);
    ret += depth[v]-depth[u];
    for (int i = 0; i < LogN; i++) {
        if ((depth[v]-depth[u]) >> i & 1) {
            v = fa[v][i];
        }
    }
    if (u == v) return ret;
    for (int i = LogN-1; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            ret += (1 << i)*2;
            u = fa[u][i];
            v = fa[v][i]; 
        }
    }
    return ret+2;
}
void dfs(int node, int from) {
    depth[node] = from >= 0 ? depth[from]+1 : 0;
    fa[node][0] = from;
    for(int i = 1; (1 << i) <= (depth[node]); i++) {
        fa[node][i] = fa[fa[node][i-1]][i-1];
    }
    for (auto subnode:tree[node]) {
        if (subnode == from) continue;
        dfs(subnode, node);
    }
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int distance = LCA_distance(x, y);
        if (distance & 1) cout << "Road\n";
        else cout << "Town\n";
    }
}

