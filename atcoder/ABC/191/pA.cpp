#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
using namespace std;
typedef long long ll;

void slove() {
    int V, T, S, D;
    cin >> V >> T >> S >> D;
    for (int i = 1; i < T; i++) {
        if (i * V >= D) {
            cout << "Yes\n";return;
        }
    }
    if (V * T > D) cout << "Yes\n";
    else cout << "No\n";
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