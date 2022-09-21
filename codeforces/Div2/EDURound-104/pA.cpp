#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n;
    cin >> n;
    int a[110];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int first = a[0], ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > first) ans++;
    }
    cout << ans << "\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}