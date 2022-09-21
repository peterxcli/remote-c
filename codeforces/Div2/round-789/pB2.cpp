// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

void solve_subtask() {
    int n, ans = 0, sum = 0;
    int cnt = 1; cin >> n;
    string a;cin >> a;

    for (int i = 0; i < n; i += 2) if (a[i] != a[i+1]) ans++;
    for (int i = 0; i < n;) {
        if (a[i] == a[i+1] && a[i] == '1') {
            while (i < n && a[i] == a[i+1] && a[i] == '1' || a[i] != a[i+1]) i += 2;
            sum++;
        }
        else if (a[i] == a[i+1] && a[i] == '0') {
            while (i < n && a[i] == a[i+1] && a[i] == '0' || a[i] != a[i+1]) i += 2;
            sum++;
        }
        else i += 2;
    }
    cout << ans << " " << (sum == 0 ? (int)1 : sum) << "\n";
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