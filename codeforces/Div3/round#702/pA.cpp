#include <bits/stdc++.h>
// #define inf (int)1e18
// #define inf (int)1e9
#define int long long
using namespace std;
typedef long long ll;

void slove() {
    int n;
    cin >> n;
    vector<int> a, tmp;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    tmp = a;
    reverse(tmp.begin(), tmp.end());
    int ans = 0, Min = INT32_MAX;
    for (int i = 0; i < a.size()-1; i++) {
        if (min(a[i], a[i+1]) * 2 < max(a[i], a[i+1])) {
            if (a[i] > a[i+1]) a.insert(a.begin()+i+1, a[i]/2 + (a[i]&1));
            else a.insert(a.begin()+i+1, a[i] * 2);
            ans ++;
        }
    }
    a = tmp;
    Min = min(Min, ans);
    ans = 0;
    for (int i = 0; i < a.size()-1; i++) {
        if (min(a[i], a[i+1]) * 2 < max(a[i], a[i+1])) {
            if (a[i] > a[i+1]) a.insert(a.begin()+i+1, a[i]/2 + (a[i]&1));
            else a.insert(a.begin()+i+1, a[i] * 2);
            ans ++;
        }
    }
    Min = min(Min, ans);
    cout << Min << "\n";
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