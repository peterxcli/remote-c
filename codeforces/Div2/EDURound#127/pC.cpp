// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int x, n;
    cin >> n >> x;
    vector<int> a(n+1, 0), b(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    for (int i = 1; i <= n; i++) b[i] = b[i-1] + a[i];
    int tmp = 0, ans = 0;
    while (b[2]+2*tmp <= x) {
        // for (int i = 1; i <= n; i++) {
        //     if (b[i] > x) {ans += i-1;; break;}
        //     if (i == n) {ans += i; break;}
        // }
        int l = 1, r = n;
        while (l < r) {
            int m = (l+r)/2;
            if (b[m] <= x - tmp * x) l = m+1;
            else r = m - 1;
            cout << l << " " << r << "\n";
        }
        cout << l << " ";
        tmp++;
        // for (int i = 1; i <= n; i++) b[i] = b[i-1] + a[i] + tmp;
    }
    cout << "\n";
    cout << ans + max(x-(a[1]+tmp-1), 0LL) << "\n";
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