#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 1;
    vector<int> order;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] > x) {
            order.emplace_back(a[i] - a[i-1]);
            ans++;
        }
    }
    sort(order.begin(), order.end());
    for (auto i : order) {
        if (k >= (i/x)+(i%x!=0)-1) {
            k -= (i/x)+(i%x!=0)-1;
            ans--;
        }
    }
    cout << ans << "\n";
    return 0;
}