// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int prefix[1005][1005], grid[1005][1005];
void solve_subtask() {
    memset(prefix, 0, sizeof prefix);
    memset(grid, 0, sizeof grid);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        grid[h][w] += h*w;
    }
    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= 1001; j++) {
            prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+grid[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        hb--, wb--;
        cout << prefix[hb][wb]-prefix[hs][wb]-prefix[hb][ws]+prefix[hs][ws] << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}