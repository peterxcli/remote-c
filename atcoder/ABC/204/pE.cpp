#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 100005
pair<int, int> edge_info[MAXN];
vector<pair<int, int> > G[MAXN];
int ans = LLONG_MAX, vis[MAXN];
bool flag = 0;
void bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        auto cur = pq.top();
        // pq.
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        G[A].emplace_back(make_pair(B, i));
        G[B].emplace_back(make_pair(A, i));
        edge_info[i].first = C, edge_info[i].second = D;
    }
    return 0;
}