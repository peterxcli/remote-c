// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    int tmp = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (tmp + x > tmp - y && tmp + x <= b) tmp += x;
        else if (tmp + x < tmp - y && tmp - y <= b) tmp -= y;
        else if (tmp + x > b) tmp -= y;
        ans += tmp;
    }
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