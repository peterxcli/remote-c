#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, X;
    cin >> N >> X;
    vector<int> a(N);
    for (auto &x : a) cin >> x;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i & 1) sum += a[i]-1;
        else sum += a[i];
    }
    if (X >= sum) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}