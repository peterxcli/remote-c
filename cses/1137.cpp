#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
void debug_out(){cerr<<"]\n"<<flush;}
template<typename Head,typename... Tail>void debug_out(Head H,Tail... T){cerr << H;if(sizeof...(T))cerr<<", ";debug_out(T...);}
#define debug(...) cerr<<"LINE("<<__LINE__<<") : ["<<#__VA_ARGS__<<"] = [";debug_out(__VA_ARGS__)
#define endl '\n'
#define int long long
const int MAXN = 2e5 + 5;
#define lowbit(x) (x & (-x))

int n, q;
vector<int> G[MAXN];
int a[MAXN], in[MAXN], out[MAXN];

int ts = 0;

void dfs(int v, int fa) {
    in[v] = ++ts;
    for (auto &u : G[v]) {
        if (u == fa) continue;
        dfs(u, v);
    }
    out[v] = ts;
}

int bit[MAXN];

void modify(int pos, int val) {
    for (int i = pos; i <= n; i += lowbit(i)) 
        bit[i] += val;
}

int query(int pos) {
    int ret = 0;
    for (int i = pos; i >= 1; i -= lowbit(i))
        ret += bit[i];
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; 
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        modify(in[i], a[i]);
    }
    for (int i = 0; i < q; i++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int s, x;
            cin >> s >> x;
            modify(in[s], -a[s]);
            a[s] = x;
            modify(in[s], a[s]);
        }
        else {
            int x;
            cin >> x;
            cout << query(out[x]) - query(in[x] - 1) << endl;
        }
    }
    return 0;
}