#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n, k;
    cin >> n >> k;
    k--;
    if (n % 2 == 0) {
        int ans = (k%n)+1;
        cout << ans << "\n";
    }
    else {
        int mid = (n/2);
        int ans = (((k/mid)+k)%n)+1;
        cout << ans << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}