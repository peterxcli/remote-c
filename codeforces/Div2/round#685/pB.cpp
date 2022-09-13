#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n, q, dp[105];
    cin >> n >> q;
    string str;
    cin >> str;
    for (int i = 0; i < q; i++) {
        int l, r, flag = 0;
        cin >> l >> r;
        for (int i = 0; i < l-1; i++) {
            if (str[i] == str[l-1]) flag = 1;
        }
        for (int i = r; i < n; i++) {
            if (str[r-1] == str[i]) flag = 1;
        }
        cout << (flag?"yes\n":"no\n");
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