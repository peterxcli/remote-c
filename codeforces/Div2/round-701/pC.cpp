#include <bits/stdc++.h>
// #define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int x, y, ans = 0;
    cin >> x >> y;
    for (int i = 1; i*i <= x; i++) {
        ans += max((ll)0, min(y, x/i-1)-i);
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
    // slove();
}