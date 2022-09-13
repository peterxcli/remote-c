#include <bits/stdc++.h>
#define inf (int)1e9
using namespace std;

int N, M, K, dist[100005][18], C[18];
vector<int> adj[100005];

void bfs(int idx) {
    for (int i = 1; i <= N; i++) dist[i][idx] = inf;
    queue<int> q;
    q.push(C[idx]); 
    dist[C[idx]][idx] = 0;    
    while(!q.empty()) {
        int cur = q.front(); 
        q.pop();
        for (auto nxt : adj[cur]) {
            if (dist[nxt][idx] == inf) {
                dist[nxt][idx] = dist[cur][idx]+1;
                q.push(nxt);
            }
        }
    }
}

int dp[18][(1<<18)];

int solve(int last, int mask) {
    if (mask == ((1 << K)-1)) {
        return 0;
    }
    int &ret = dp[last][mask];
    if (ret != -1) return ret;
    ret = inf;
    for (int i = 0; i < K; i++) {
        if (mask & (1 << i)) continue;
        ret = min(ret, solve(i, mask | (1 << i)) + dist[C[last]][i]);
    }
    return ret;
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < K; i++)
        bfs(i);
    for (int i = 0; i < K; i++) {
        if (dist[C[0]][i] == inf) return cout << "-1\n", 0;
    }
    int ans = inf;
    for (int i = 0; i < K; i++) {
        ans = min(ans, 1+solve(i, (1 << i)));
    }
    cout << ans << "\n";
}