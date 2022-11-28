#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) begin(a), end(a)
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
const int mod = 998244353;
const int inf = 1e18;
const int MAXN = 1000005;

int pos1, pos2;
vector<pii> edge[MAXN];
int n, a, b;
set<int> s;

void dfs1(int fa, int now, int val) {
    if(fa) s.insert(val);

    for (auto i : edge[now]) {
        if (i.F == b) continue;
        if (i.F != fa) {
            // s.insert(val ^ i.S);
            dfs1(now, i.F, val ^ i.S); 
        }
    }
}

bool dfs2(int fa, int now, int val) {
    if(s.count(val)) return true;
    for (auto i : edge[now]) {
        // if (i.F == a) continue;
        if (i.F == b) continue;
        if (i.F != fa) {
            // if (s.count(val ^ i.S)) return true;
            if (dfs2(now, i.F, val ^ i.S)) return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) edge[i].clear();
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].pb({v, w});
        edge[v].pb({u, w});
    }
    // dfs1(0, a, 0);
    dfs1(0, b, 0);
    // if (s.count(0)) cout << "YES\n";
    if (dfs2(0, a, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
    cin.sync_with_stdio(0), cin.tie(0);
    int N = 1;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        solve();
        s.clear();
    }
}
