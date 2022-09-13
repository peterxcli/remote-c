#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    if (x == y) cout << x << "\n";
    else {
        for (int i = 0; i < 3; i++) {
            if (i != x && i != y) cout << i << "\n";
        }
    }
    return 0;
}