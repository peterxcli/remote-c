//https://codeforces.com/contest/1476/problem/B
#include <bits/stdc++.h>

#define int double

using namespace std;

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int32_t t;
    cin >> t;
    while(t--) {
        int32_t n, ans = 0;
        int k;
        cin >> n >> k;
        k /= 100;
        vector<int> p;
        p.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int sum = p[0];
        for (int i = 1; i < n; i++) {
            if (sum/p[i-1] > k) {
                ans += ceil((sum*k-p[i])/(1-k));
                p[i] += ceil((sum*k-p[i])/(1-k));
            }
            sum += p[i];
        }
        cout << ans << "\n";
    }
}