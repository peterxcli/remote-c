#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
#define MAXN 1005

int vis[MAXN][MAXN], dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}, n, m;

string grid[1005];

void dfs(int r, int c) {
    vis[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int new_r = r + dir[i][0], new_c = c + dir[i][1];
        if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= m) continue;
        if (grid[new_r][new_c] == '#' || vis[new_r][new_c]) continue;
        dfs(new_r, new_c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}