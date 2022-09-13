#include <bits/stdc++.h>
#define inf (long long)1e18
#define MAXN 100010
// #define inf (int)1e9
// #define int long long
using namespace std;
typedef long long ll;

int a[MAXN];

void query(int x) {
    cout << "? " << x << endl;
    cout.flush();
    cin >> a[x];
}

void slove() {
    int n;
    memset(a, 0, sizeof a);
    cin >> n;
    a[0] = a[n+1] = INT32_MAX;
    int l = 1, r = n;
    while(l != r) {
        int m = (l+r)>>1;
        query(m);
        query(m+1);
        if (a[m] > a[m+1]) {
            l = m+1;
        }
        else {
            r = m;
        }
    }
    cout << "! " << l << endl;
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