// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 >= l2 && l1 <= r2) cout << l1 << "\n";
    else if (l2 >= l1 && l2 <= r1) cout << l2 << "\n";
    else cout << l1+l2 << "\n";
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