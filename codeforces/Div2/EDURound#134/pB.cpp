// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, m, s_x, s_y, d;
    cin >> n >> m >> s_x >> s_y >> d;
    swap(n, m);
    if ((s_x - 1 <= d || n - s_y <= d) && (m - s_x <= d || s_y - 1 <= d)) cout << -1 << "\n";
    else cout << n + m - 2 << "\n";
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