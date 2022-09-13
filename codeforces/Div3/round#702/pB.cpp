#include <bits/stdc++.h>
// #define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n, c[3], ans = 0;
    c[0] = c[1] = c[2] = 0;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]%3]++;
    }
    if (c[0] == c[1] && c[1] == c[2]) {cout << ans; return;}
    if (c[0] > n/3 && c[1] < n/3) {
        if (c[0]-n/3 > n/3-c[1]) {
            ans += n/3-c[1];
            c[0] -= n/3-c[1];
            c[1] = n/3;
        }
        else {
            ans += n/3-c[1];
            c[0] -= n/3-c[1];
            c[1] = n/3;
        }
    }
    
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