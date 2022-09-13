#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
int query(int m) {
    cout << "? " << m << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int32_t main() {
    int n; cin >> n;
    int l = 1, r = 4000000;
    while (l < r) {
        int m = (l+r)/2;
        if (query(m) == 1) r = m;
        else l = m+1;
    }
    int ans = l;
    for (int i = 1; i <= n; i++) {
        int w = query( ceil((l - i + 1) * 1.0 / i));
        if (w == 0) continue;
        ans = min(ans, w * (int)ceil((l - i + 1) * 1.0 / i));
    }
    cout << "! " << ans << "\n";
    cout.flush();
}