//https://codeforces.com/problemset/problem/466/C
#include <bits/stdc++.h>
#define maxn 1000010
#define int long long
using namespace std;

int cnt[maxn], a[maxn], sum[maxn];

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0) return cout << "0\n", 0;
    s /= 3;
    int ss = 0;
    for (int i = n-1; i >= 0; i--) {
        ss += a[i];
        if (ss == s) {
            cnt[i] = 1;
        }
    }
    sum[n-1] = cnt[n-1];
    for (int i = n-2; i >= 0; i--) {
        sum[i] += sum[i+1]+cnt[i];
    }
    ss = 0;
    int ans = 0;
    for (int i = 0; i < n-2; i++) {
        ss += a[i];
        if (ss == s) {
            ans += sum[i+2];
        }
    }
    cout << ans << endl;
}   
