//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, x, y; 
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> v;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) v.emplace_back(i);
    if (a == b) cout << 0 << "\n";
    else if (v.size() & 1) cout <<  -1 << "\n";
    else if (v.size() > 2) {
        cout << v.size() / 2 * y << "\n";
    }
    else { // v.size() == 2
        if (v[0]+1 == v[1]) cout << min(x, y*2) << "\n";
        else cout << y << "\n";
    }

    
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}