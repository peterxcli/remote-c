#include <bits/stdc++.h>
// #define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int a, b;
    cin >> a >> b;
    int ans = 0, tmp = INT32_MAX;
    if (b == 1) {ans ++;b++;}
    for (int i = 0; i <= 100000; i++) {
        int tmp_a = a, tmp_b = b+i, tmp_ans = i;
        while (tmp_a != 0) {
            tmp_a /= tmp_b;
            tmp_ans++;
        }
        tmp = min(tmp, tmp_ans);
    }
    ans += tmp;
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