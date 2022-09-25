//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MAXN 200005
struct Node {
    int a, b, child;
    // Node(int _a, int _b, int _ch) {
    //     a = _a, b = _b, child = _ch;
    // }
};

vector<Node> G[MAXN]; 
int f[MAXN], b_sum[MAXN], len[MAXN], a_sum[MAXN];
vector<int> prefix;

void dfs(int x) {
    if (G[x].size() == 0) return;
    for (auto node : G[x]) {
        b_sum[node.child] = b_sum[x] + node.b;
        a_sum[node.child] = a_sum[x] + node.a;
        prefix.push_back(b_sum[node.child]);
        len[node.child] = upper_bound(prefix.begin(), prefix.end(), a_sum[node.child]) - prefix.begin(); 
        dfs(node.child);
        prefix.pop_back();
    }
}

void solve_subtask() {
    prefix.clear();
    int n; cin >> n;
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 2; i <= n; i++) {
        int p, a, b;
        cin >> p >> a >> b;
        G[p].push_back({a, b, i});
        //cout << G[p][0].a << " " << G[p][0].b << " " << G[p][0].child << endl; 
    }
    dfs(1);
    for (int i = 2; i <= n; i++) cout << len[i] << (i == n?'\n':' ');
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}