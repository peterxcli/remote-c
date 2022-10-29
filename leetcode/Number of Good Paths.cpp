#pragma GCC optimize("O2,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

class Solution {
int find(int &x, vector<int> &fa) {
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x], fa);
}

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b) {
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
        });
        vector<int> sz(n), mx(n), fa(n);
        for (int i = 0; i < n; i++) fa[i] = i, mx[i] = vals[i], sz[i] = 1;
        int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = find(edges[i][0], fa), v = find(edges[i][1], fa);
            if (mx[u] == mx[v]) {
                ans += sz[u] * sz[v];
                if (sz[u] < sz[v]) swap(u, v);
                sz[u] += sz[v];
                fa[v] = u;
            }
            else {
                if (mx[u] > mx[v]) fa[v] = u;
                else fa[u] = v;
            }
        }
        return ans+n;
    }
};