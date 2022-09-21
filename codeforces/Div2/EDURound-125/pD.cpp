// codeforces template
// #define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
#define MAXN 300005
int f[1000005];

void solve_subtask() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        f[a] = max(b*c, f[a]);
    }
    for (int i = 1; i <= c; i++) {
        if (f[i] == 0) continue;
        for (int j = 1; i*j <= c; j++) {
            f[i*j] = max(f[i*j], f[i]*j);
        }
    }
    for (int i = 1; i <= c; i++) f[i] = max(f[i], f[i-1]);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int ans = upper_bound(f, f+c+1, a*b) - f;
        cout << (ans <= c ? ans : -1) << " ";
    }
    cout << "\n";
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