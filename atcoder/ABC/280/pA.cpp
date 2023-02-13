#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W;
    cin >> H >> W;
    int ans = 0;
    for (int i = 0; i < H; i++) {
        string str;
        cin >> str;
        for (auto x : str) {
            if (x == '#') ans++;
        }

    }
    cout << ans << "\n";
    return 0;
}