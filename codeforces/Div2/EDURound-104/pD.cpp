#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n;
    cin >> n;
    int ans = 0;
    for (int a = 2; a*a <= 2*n+1; a++) {
        if (a % 2 == 0) continue;
        int b = (a*a-1) / 2;
        int c = (a*a+1)/2;
        if (b > n || c > n) continue;
        ans++; 
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