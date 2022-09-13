#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin >> n;
    int a, b, c, ans = 0;
    while (n--) {
        cin >> a >> b >> c;
        int tmp = 0;
        if (a) tmp++;
        if (b) tmp++;
        if (c) tmp++;
        if (tmp >= 2) ans++;
    }
    cout << ans << "\n";
    return 0;
}