#include <bits/stdc++.h>

using namespace std;

int n, m, vertex[200100], cnt;
long long ans;

struct Edge {
    int weight, l, r;
}edge[200100];

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int query(int n) {
    if (vertex[n] == n) return n;
    else return vertex[n] = query(vertex[n]);
}

int main() {
    while(cin >> n >> m) {
        ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) vertex[i] = i;
        for (int i = 0; i < m; i++) cin >> edge[i].l >> edge[i].r >> edge[i].weight;
        
        sort(edge, edge+m, cmp);
        for (int i = 0; i < m; i++) {
            if (query(edge[i].l) != query(edge[i].r)) {
                ans += edge[i].weight;
                vertex[query(edge[i].l)] = query(edge[i].r);
                cnt++;
            }
            if (cnt == n-1) break;
        }
        cout << (cnt == n-1?ans:-1) << endl;
    }
}

