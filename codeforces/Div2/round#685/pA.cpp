#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
// #define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n, ans = 0;
    cin >> n;
    if (n == 1) cout << "0\n";
    else if (n == 2) cout << "1\n";
    else if (n == 3) cout << "2\n";
    else if (n % 2 == 0) cout << "2\n";
    else cout << "3\n";
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);   
    int t;
    cin >> t;
    while(t--) {
        slove();
    }
}