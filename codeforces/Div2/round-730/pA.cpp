//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int a, b;
    cin >> a >> b;
    int x = abs(a-b);
    if (x == 0) cout << 0 << " " << 0 << "\n";
    else cout << x << " " << min(min(x-(a%x), a%x), min(a, b)) << "\n";
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