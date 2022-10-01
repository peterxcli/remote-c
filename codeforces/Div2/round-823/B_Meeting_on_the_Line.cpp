// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define double long double
using namespace std;


// int calc(int m) {
//     int ret = 0.0;
//     for (int i = 0; i < x.size(); i++) {
//         ret = max(abs(m-x[i]) + t[i], ret);
//     }
//     return ret;
// }

void solve_subtask() {
    int n; cin >> n;
    vector<int> x(n), t(n);
    // x.resize(n), t.resize(n);
    for (auto &i : x) cin >> i;
    for (auto &i : t) cin >> i;
    int l = INT64_MAX, r = INT64_MIN;
    for (int i = 0; i < n; i++) {
        l = min({l, x[i] + t[i], x[i] - t[i]});
        r = max({r, x[i] + t[i], x[i] - t[i]});
    }
    cout << (l + r) / 2;
    if ((l+r) & 1) cout << ".5" << "\n";
    else cout << "\n";
    return;
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