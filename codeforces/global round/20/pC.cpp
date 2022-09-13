#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int e = 0, s = n-1;
    for (int i = n-1; i >= 1; i--) {
        if (a[i] == a[i-1]) {
            e = i;
            break;
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (a[i] == a[i+1]) {
            s = i;
            break;
        }
    }
    if (e-s+1 == 3) {
        cout << 1 << "\n";
        return;
    }
    if (e-s+1 == 2) {
        cout << 0 << "\n";
        return;
    }
    cout << max((int)0, e-s-2) << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cnt = 1;
    cin >> cnt;
    while (cnt--) solve();
}