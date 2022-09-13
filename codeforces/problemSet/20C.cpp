#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 100005
int n, m, from[MAXN], dis[MAXN];
vector<pair<int, int> > G[MAXN];

void bfs() {
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.emplace(make_pair(0, 1));
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.second == n) {
            return;
        }
        for (auto v : G[cur.second]) {
            if (dis[v.first] > dis[cur.second] + v.second) {
                dis[v.first] = dis[cur.second] + v.second;
                from[v.first] = cur.second;
                pq.emplace(make_pair(dis[cur.second] + v.second, v.first));
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(make_pair(v, w));
        G[v].emplace_back(make_pair(u, w));
    }
    bfs();
    if (from[n] == 0) cout << "-1\n";
    else {
        vector<int> ans;
        ans.emplace_back(n);
        while (ans.back() != 1) {
            ans.emplace_back(from[ans.back()]);
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}