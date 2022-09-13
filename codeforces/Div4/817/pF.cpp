// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

const int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};

string grid[55];
void solve_subtask() {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    int id[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            id[i][j] = 0;
        }
    }
    int curr = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') {
                vector<pair<int, int>> adjh, adjv;
                if (i > 0 && g[i - 1][j] == '*') {
                    adjh.emplace_back(i - 1, j);
                }
                if (i < n - 1 && g[i + 1][j] == '*') {
                    adjh.emplace_back(i + 1, j);
                }
                if (j > 0 && g[i][j - 1] == '*') {
                    adjv.emplace_back(i, j - 1);
                }
                if (j < m - 1 && g[i][j + 1] == '*') {
                    adjv.emplace_back(i, j + 1);
                }
                if (adjh.size() == 1 && adjv.size() == 1) {
                    if (id[i][j] == 0) {
                        id[i][j] = curr;
                    } else {
                        cout << "NO\n";
                        return;
                    }
                    if (id[adjh[0].first][adjh[0].second] == 0) {
                        id[adjh[0].first][adjh[0].second] = curr;
                    } else {
                        cout << "NO\n";
                        return;
                    }
                    if (id[adjv[0].first][adjv[0].second] == 0) {
                        id[adjv[0].first][adjv[0].second] = curr;
                    } else {
                        cout << "NO\n";
                        return;
                    }
                    curr++;
                } else if (adjh.size() > 1 || adjv.size() > 1) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') {
                if (id[i][j] == 0) {
                    cout << "NO\n";
                    return;
                } else {
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            if (0 <= i + dx[x] && i + dx[x] < n) {
                                if (0 <= j + dy[y] && j + dy[y] < m) {
                                    if (id[i + dx[x]][j + dy[y]] != id[i][j] && id[i + dx[x]][j + dy[y]] != 0) {
                                        cout << "NO\n";
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "YES\n";
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