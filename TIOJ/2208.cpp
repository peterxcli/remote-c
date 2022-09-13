#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define MAXN 1005
#define int long long
int N, M, p, q, a, b, grid[MAXN][MAXN], vis[MAXN][MAXN], tmp[MAXN][MAXN];

int bfs(int s_r, int s_c, int e_r, int e_c) {
    int dir[8][2] = {{0, p}, {0, -p}, {0, q}, {0, -q}, {p, 0}, {-p, 0}, {q, 0}, {-q, 0}};
    int ret = LLONG_MAX;
    vis[s_r][s_r] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;
    q.emplace(make_pair(0, make_pair(s_r, s_c)));
    while (!q.empty()) {
        auto cur = q.top(); q.pop();
        int r = cur.second.first, c = cur.second.second, dis = cur.first;
        if (r == e_r && c == e_c) {
            ret = dis;
            break;
        }
        for (int i = 0; i < 8; i++) {
            int new_r = r + dir[i][0], new_c = c + dir[i][1];
            if (new_r <= 0 || new_r > N || new_c <= 0 || new_c > M) continue;
            if (grid[new_r][new_c]) continue;
            if (tmp[new_r][new_c] > tmp[r][c]+1) {
                q.emplace(make_pair(dis + 1, make_pair(new_r, new_c)));
                tmp[new_r][new_c] = tmp[r][c]+1;
            }
        }
    }
    while (!q.empty()) q.pop();
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> p >> q;
    cin >> a >> b;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> grid[i][j];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) tmp[i][j] = LLONG_MAX;
    int ans1 = bfs(1, 1, a, b);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) tmp[i][j] = LLONG_MAX;
    int ans2 = bfs(a, b, N, M);
    if (ans1 == LLONG_MAX || ans2 == LLONG_MAX) cout << "-1\n";
    else cout << ans1 + ans2 << "\n";
    return 0;
}