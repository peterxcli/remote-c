// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        b[i % k] = max(b[i % k], a[i]);
    }
    int ans = 0;
    for (auto x : b) ans += x;
    cout << ans << "\n";
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