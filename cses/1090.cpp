#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (auto &i : p) cin >> i;
    sort(p.begin(), p.end());
    int l = 0, r = p.size() - 1, ans = 0;
    while (l <= r) {
        if (l == r) {
            ans++;
            break;
        }
        else if (p[r] + p[l] <= x) {
            ans++;
            r--, l++;
        }
        else {
            ans++;
            r--;
        }
    }//2 3 7 9
    cout << ans << "\n";
    return 0;
}