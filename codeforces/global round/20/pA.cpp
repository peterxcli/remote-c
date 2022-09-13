#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    sum -= n;
    if (sum % 2 == 1) cout << "errorgorn\n";
    else cout << "maomao90\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cnt;
    cin >> cnt;
    while (cnt--) solve();
}