#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll s, t, N, M, c[205], dp[205][1005];

vector<int> vertex[205];


ll dfs(ll v, ll step, ll sum) {
    if(step == t) return dp[v][t-step] = sum;
    if (dp[v][t-step] != -1) return dp[v][t-step];
    ll ret = LLONG_MIN;
    for (int i = 0; i < vertex[v].size(); i++) {
        ret = max(ret, dfs(vertex[v][i], step+1, sum+c[vertex[v][i]]));
    }
    return dp[v][step] = ret;
}

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> N >> M >> s >> t;
    memset(dp, -1, sizeof(dp));
    s--;
    for (int i = 0; i < N; i++) 
        cin >> c[i];
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        vertex[u].push_back(v);
    }

    cout << dfs(s, 0, 0) << "\n";
}
