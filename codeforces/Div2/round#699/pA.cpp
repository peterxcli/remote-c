#include <bits/stdc++.h>
#define inf (int)1e18
// #define inf (int)1e9
#define int long long 
using namespace std;
typedef long long ll;

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int px, py;
        cin >> px >> py;
        string dir;
        cin >> dir;
        int U = 0, D = 0, R = 0, L = 0;
        for (int i = 0; i < dir.size(); i++) {
            if (dir[i] == 'U') U++;//y++
            else if (dir[i] == 'D') D++;//y--
            else if (dir[i] == 'R') R++;// x++
            else if (dir[i] == 'L') L++;//x--
        }
        if (px >= 0 && py >= 0) {
            if (R < px || U < py) cout << "NO\n";
            else cout << "YES\n";
        }
        else if (px >= 0 && py <= 0) {
            if (R < abs(px) || D < abs(py)) cout << "NO\n";
            else cout << "YES\n";
        }
        else if (px <= 0 && py >= 0) {
            if (L < abs(px) || U < abs(py)) cout << "NO\n";
            else cout << "YES\n";
        }
        else if (px <= 0 && py <= 0) {
            if (L < abs(px) || D < abs(py)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}