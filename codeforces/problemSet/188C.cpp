// https://codeforces.com/problemset/problem/188/C
#include <bits/stdc++.h>
// #define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    cout << a*b/__gcd(a, b) << "\n";
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