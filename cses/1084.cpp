#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p1 = 0, p2 = 0, ans = 0;
    while (p1 < n) {
        while (p2 < m && (b[p2] < a[p1] - k || b[p2] > a[p1] + k)) {
            if (a[p1] + k < b[p2]) p1++;
            else p2++;
        }
        if (p2 >= m || p1>=n) break;
        // cout << a[p1] << " " << b[p2] << "\n";
        p1++;
        p2++;
        ans++;
    }
    cout << ans << "\n";
    return 0;
    // 4 3 5
    // 45 60 60 80
    // 30 60 75
}