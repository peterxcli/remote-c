// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    pair<int, int> one, two;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'R') {
                one.first = i, one.second = j;
                i = n;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'R') {
                two.first = i, two.second = j;
                j = m;
                break;
            }
        }
    }
    if (two.first == one.first && two.second == one.second) cout << "yes\n";
    else cout << "no\n";
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