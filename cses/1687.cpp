//LCA
//link:https://tioj.ck.tp.edu.tw/problems/2172
#include <bits/stdc++.h>
#define N 200005
#define LogN 40
using namespace std;

int n, m, depth[N], fa[N][LogN];
vector<int> tree[N];

// int LCA(int u, int v) {
//     if (depth[u] > depth[v]) swap(u, v);
//     for (int i = 0; i < LogN; i++) {
//         if ((depth[v]-depth[u]) >> i & 1) {
//             v = fa[v][i];
//         }
//     }
//     if (u == v) return u;
//     for (int i = LogN-1; i >= 0; i--) {
//         if (fa[u][i] != fa[v][i]) {
//             u = fa[u][i];
//             v = fa[v][i]; 
//         }
//     }
//     return fa[u][0];
// }
void dfs(int node, int from) {
    depth[node] = from >= 1 ? depth[from] + 1 : 0;
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
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x; y = i + 2;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        int x, k;
        cin >> x >> k;
        if (k > depth[x]) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = k, j = 0; k; k >>= 1, j++) {
            if (k & 1) x = fa[x][j];
        }
        cout << x << "\n";
    }
}

