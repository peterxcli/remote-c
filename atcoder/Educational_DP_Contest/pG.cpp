#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

ll n, m, dp[100005] = {-1};
vector<ll> vertex[100005];

ll dfs(ll v);

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        vertex[x].push_back(y);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans = max(ans, dfs(i));
    }

    cout << ans << endl;
    return 0;
}

ll dfs(ll v) {
    if (dp[v] != -1) return dp[v];
    ll ret = 0;
    for (ll i = 0; i < vertex[v].size(); i++) 
        ret = max(ret, dfs(vertex[v][i]) +1 );
    return dp[v] = ret;
}
