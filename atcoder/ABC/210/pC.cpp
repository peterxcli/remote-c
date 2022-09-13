#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    for (auto &x : c) cin >> x;
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < c.size(); i++) {
        mp[c[i]]++;
        if (i >= K) {
            auto tmp = c[i-K];
            if (mp.find(tmp) != mp.end()) {
                mp[tmp]--;
                if (mp[tmp] == 0) mp.erase(tmp);
            }
        }
        ans = max(ans, (int)mp.size());
        // cout << mp.size() << "\n";
        // for (auto x : mp) cout << x.first << " " << x.second << " ";
        // cout << "\n";
    }
    cout << ans << "\n";
    return 0;
}