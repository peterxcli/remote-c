#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200005
const int mod = 1e9+7;

vector<int> adj[MAXN];
int dist[MAXN], paths[MAXN];
bool visited[MAXN];
int n, m;

void BFS(int src, int tar) {
    for (int i = 0; i <= n; i++) visited[i] = false;
    dist[src] = 0;
    paths[src] = 1;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto x : adj[cur]) {
            if (visited[x] == false) {
                q.push(x);
                visited[x] = true;
            }
            if (dist[x] > dist[cur] + 1) {
                dist[x] = dist[cur] + 1;
                paths[x] = paths[cur] % mod;
            }
            else if (dist[x] == dist[cur] + 1) paths[x] = (paths[x] + paths[cur]) % mod;
        }
    }
}

int32_t main() {
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i <= n; i++) dist[i] = INT_MAX;
    for (int i = 0; i <= n; i++) paths[i] = 0;
    BFS(1, n);
    cout << paths[n] << "\n";
    return 0;
}