#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        b.assign(n, 0);
        int tmp = 0;
        for (int l = i-1; l >=0; l--) {
            tmp += (abs(b[l+1]) / a[l]) + 1;
            b[l] = -((abs(b[l+1]) / a[l]) + 1) * a[l];
        }
        for (int r = i+1; r < n; r++) {
            tmp += (b[r-1] / a[r]) + 1;
            b[r] = ((b[r-1] / a[r]) + 1) * a[r];
        }
        ans = min(ans, tmp);
        // for (auto x : b) cout << x << " ";
        // cout << "\n";
    }
    cout << ans << "\n";
    return 0;
}