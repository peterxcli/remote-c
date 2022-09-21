#include <bits/stdc++.h>
// #define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << (a[l]-1) + (k-a[r]) + 2 * ((a[r]-a[l]+1) -(r-l+1)) << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    // int t;
    // cin >> t;
    // while(t--) {
    //     slove();
    // }
    slove();
}